// Last updated: 02/05/2026, 22:34:50
class Solution {
public:
    class DSU {
    public:
        vector<int> parent;
        vector<int> size;

        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] == x)
                return x;

            return parent[x] = find(parent[x]); // Path compression
        }

        void Union(int x, int y) {
            int x_parent = find(x);
            int y_parent = find(y);

            if (x_parent == y_parent)
                return;

            if (size[x_parent] > size[y_parent]) {
                parent[y_parent] = x_parent;
                size[x_parent] += size[y_parent];
            } else {
                parent[x_parent] = y_parent;
                size[y_parent] += size[x_parent];
            }
        }
    };

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        unordered_map<int, int> edgeCount; // Stores root -> number of edges

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            dsu.Union(u, v);
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int root = dsu.find(u);
            edgeCount[root]++;
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) { // Only check unique component roots
                int v = dsu.size[i];
                int e = edgeCount[i];

                if ((v * (v - 1)) / 2 == e) {
                    result++;
                }
            }
        }

        return result;
    }
};