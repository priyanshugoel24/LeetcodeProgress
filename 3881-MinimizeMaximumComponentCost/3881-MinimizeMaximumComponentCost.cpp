// Last updated: 02/05/2026, 22:32:23
class Solution {
public:
    class DSU {
        vector<int> parent;
        vector<int> rank;
        int size;

        public:
        DSU(int n) {
            parent.resize(n);
            rank.resize(n);
            size = n;
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int findPar(int u) {
            if (parent[u] != u) {
                parent[u] = findPar(parent[u]);
            }
            return parent[u];
        }

        void Union(int u, int v) {
            int par_u = findPar(u);
            int par_v = findPar(v);
            if (par_u == par_v) return;

            if (rank[par_u] > rank[par_v]) {
                parent[par_v] = par_u;
            } else if (rank[par_u] < rank[par_v]) {
                parent[par_u] = par_v;
            } else {
                parent[par_u] = par_v;
                rank[par_v]++;
            }

            size--;
        }

        int getSize() {
            return size;
        }
    };

    bool isPossible(int cost, unordered_map<int, vector<pair<int, int>>>& adj, int k, int n) {
        DSU dsu(n);

        for (auto& [u, neighbors] : adj) {
            for (auto& [v, wt] : neighbors) {
                if (wt <= cost) {
                    dsu.Union(u, v);
                }
            }
        }

        int no_of_components = dsu.getSize();

        if(no_of_components > k){
            return false;
        }

        return true;
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {
        int minEdgeWt = INT_MAX;
        int maxEdgeWt = INT_MIN;

        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
            minEdgeWt = min(minEdgeWt, wt);
            maxEdgeWt = max(maxEdgeWt, wt);
        }

        int l = 0, r = maxEdgeWt;
        int minPossibleCost = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(mid, adj, k, n)) {
                minPossibleCost = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return minPossibleCost;
    }
};
