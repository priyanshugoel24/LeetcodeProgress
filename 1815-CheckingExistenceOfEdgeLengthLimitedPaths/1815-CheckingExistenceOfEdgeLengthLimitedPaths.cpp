// Last updated: 02/05/2026, 22:38:46
class Solution {
public:
    // Disjoint Set Union (Union-Find) data structure
    class DSU {
        vector<int> parent;
        vector<int> rank; // used for union by rank optimization

    public:
        // Constructor to initialize DSU with `n` nodes
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0); // all ranks start at 0
            for (int i = 0; i < n; i++) {
                parent[i] = i; // initially each node is its own parent
            }
        }

        // Find function with path compression
        int findPar(int x) {
            if (parent[x] != x) {
                parent[x] = findPar(parent[x]); // path compression
            }
            return parent[x];
        }

        // Union two sets using rank
        void Union(int x, int y) {
            int par_x = findPar(x);
            int par_y = findPar(y);

            // Already in same set
            if (par_x == par_y) return;

            // Attach smaller tree under larger tree
            if (rank[par_x] > rank[par_y]) {
                parent[par_y] = par_x;
            } else if (rank[par_x] < rank[par_y]) {
                parent[par_x] = par_y;
            } else {
                parent[par_y] = par_x;
                rank[par_x]++; // increase rank only if both are same
            }
        }
    };

    vector<bool> distanceLimitedPathsExist(
        int n,
        vector<vector<int>>& edgeList,
        vector<vector<int>>& queries
    ) {
        // Step 1: Add original index to each query so that we can return answers in original order
        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i); // append query index at the end
        }

        // Step 2: Sort edgeList by edge weight (ascending)
        sort(edgeList.begin(), edgeList.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        // Step 3: Sort queries by limit (ascending)
        sort(queries.begin(), queries.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        DSU dsu(n); // Initialize DSU with `n` nodes
        vector<bool> result(queries.size()); // answer array
        int j = 0; // pointer for edgeList

        // Step 4: Process each query in increasing order of limit
        for (auto& query : queries) {
            int u = query[0];      // source node
            int v = query[1];      // target node
            int limit = query[2];  // edge weight limit
            int idx = query[3];    // original index of query

            // Process and union all edges with weight < limit
            while (j < edgeList.size() && edgeList[j][2] < limit) {
                dsu.Union(edgeList[j][0], edgeList[j][1]); // connect nodes
                j++;
            }

            // After unioning all valid edges, check if u and v are connected
            result[idx] = dsu.findPar(u) == dsu.findPar(v);
        }

        // Step 5: Return results in original query order
        return result;
    }
};
