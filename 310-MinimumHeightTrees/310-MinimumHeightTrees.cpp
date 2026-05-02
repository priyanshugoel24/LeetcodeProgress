// Last updated: 02/05/2026, 22:45:35
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);  // leaf node
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int size = q.size();
            result.clear(); // nodes in current layer

            for (int i = 0; i < size; i++) {
                int node = q.front(); q.pop();
                result.push_back(node);

                for (int neighbor : adj[node]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        return result;
    }
};
