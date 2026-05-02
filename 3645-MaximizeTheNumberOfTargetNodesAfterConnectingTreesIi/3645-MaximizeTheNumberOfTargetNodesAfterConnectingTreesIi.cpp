// Last updated: 02/05/2026, 22:32:55
class Solution {
public:
    void dfsCount(int node, int parent, unordered_map<int, vector<int>>& adj, vector<int>& evenCount, vector<int>& depth) {
        for (int nbr : adj[node]) {
            if (nbr == parent) continue;
            depth[nbr] = depth[node] + 1;
            dfsCount(nbr, node, adj, evenCount, depth);
        }
    }

    vector<int> findEvenCountFromEachNode(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        unordered_map<int, vector<int>> adj;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // First DFS from node 0 to compute depth of each node
        vector<int> depth(n, 0);
        dfsCount(0, -1, adj, depth, depth);  // depth doubles as visited here

        // Count even and odd nodes globally
        int evenTotal = 0, oddTotal = 0;
        for (int d : depth) {
            if (d % 2 == 0) evenTotal++;
            else oddTotal++;
        }

        // Second DFS to reroot and fill result efficiently
        vector<int> result(n);
        function<void(int, int, int)> reroot = [&](int node, int parent, int evenFromParent) {
            result[node] = evenFromParent;

            for (int nbr : adj[node]) {
                if (nbr == parent) continue;

                int newEven;
                // Move root from node to nbr:
                if ((depth[nbr] - depth[node]) % 2 == 1) {
                    // Parity flips
                    newEven = (n - evenFromParent);
                } else {
                    // Parity remains
                    newEven = evenFromParent;
                }
                reroot(nbr, node, newEven);
            }
        };

        reroot(0, -1, evenTotal); // Start rerooting from node 0
        return result;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<int> targetNodes1 = findEvenCountFromEachNode(edges1);
        vector<int> targetNodes2 = findEvenCountFromEachNode(edges2);

        int maxTargetNodesCount = *max_element(targetNodes2.begin(), targetNodes2.end());

        for (int i = 0; i < targetNodes1.size(); i++) {
            targetNodes1[i] += maxTargetNodesCount;
        }

        return targetNodes1;
    }
};