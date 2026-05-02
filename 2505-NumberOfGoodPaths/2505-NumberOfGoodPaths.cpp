// Last updated: 02/05/2026, 22:35:52
class Solution {
public:
    // Disjoint Set Union (DSU) / Union-Find class
    class DSU {
        vector<int> parent;
        vector<int> rank;

    public:
        // Constructor to initialize DSU for 'n' elements
        DSU(int n) {
            parent.resize(n);
            rank.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i; // Initially, each node is its own parent
            }
        }

        // Find with path compression
        int findPar(int u) {
            if (parent[u] != u) {
                parent[u] = findPar(parent[u]); // Compress path
            }
            return parent[u];
        }

        // Union by rank
        void Union(int u, int v) {
            int par_u = findPar(u);
            int par_v = findPar(v);

            // If both nodes have the same parent, already connected
            if (par_u == par_v) return;

            // Attach the smaller tree under the bigger tree
            if (rank[par_u] > rank[par_v]) {
                parent[par_v] = par_u;
            } else if (rank[par_u] < rank[par_v]) {
                parent[par_u] = par_v;
            } else {
                // If ranks are equal, attach and increase rank
                parent[par_v] = par_u;
                rank[par_u]++;
            }
        }
    };

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        DSU dsu(n);  // Create DSU for 'n' nodes

        // Build the graph as an adjacency list
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Group nodes by their values
        map<int, vector<int>> val_to_nodes;
        for (int i = 0; i < n; i++) {
            val_to_nodes[vals[i]].push_back(i);
        }

        int result = n;  // Start with all single-node paths (each is a good path)

        vector<bool> is_active(n, false); // Track which nodes are activated

        // Process nodes in increasing order of their value
        for (auto &it : val_to_nodes) {
            vector<int> nodes = it.second;

            // Activate nodes of the current value
            for (int &u : nodes) {
                for (int &v : adj[u]) {
                    // If neighbor is already active, union them
                    if (is_active[v]) {
                        dsu.Union(u, v);
                    }
                }
                is_active[u] = true; // Mark current node as active
            }

            // Count how many nodes with the same value share the same parent
            vector<int> nodes_parent;
            for (int &u : nodes) {
                int parent = dsu.findPar(u);
                nodes_parent.push_back(parent);
            }

            // Sort to group same parents together
            sort(nodes_parent.begin(), nodes_parent.end());

            int size = nodes_parent.size();

            // Count combinations of nodes in the same group
            for (int j = 0; j < size; j++) {
                long long count = 0;
                int curr_parent = nodes_parent[j];

                // Count how many nodes have the same parent
                while (j < size && nodes_parent[j] == curr_parent) {
                    j++;
                    count++;
                }
                j--; // Adjust index after while loop

                // Add the number of good paths from this group
                int formula = (count * (count - 1)) / 2; // C(n, 2)
                result += formula;
            }
        }

        return result;
    }
};
