// Last updated: 02/05/2026, 22:41:08
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
                }
            }

            int findPar(int x) {
                if (parent[x] != x) {
                    parent[x] = findPar(parent[x]);
                }
                return parent[x];
            }

            void Union(int x, int y) {
                int par_x = findPar(x);
                int par_y = findPar(y);

                if (par_x == par_y) return;

                if (rank[par_x] > rank[par_y]) {
                    parent[par_y] = par_x;
                } else if (rank[par_x] < rank[par_y]) {
                    parent[par_x] = par_y;
                } else {
                    parent[par_y] = par_x;
                    rank[par_x]++;
                }

                size--;
            }

            int getSize() {
                return size;
            }
    };

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DSU dsu(n);
        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; i++) {
            int u = i;

            if (leftChild[i] != -1) {
                int v = leftChild[i];

                inDegree[v]++;
                if (inDegree[v] > 1) return false;

                if (dsu.findPar(u) == dsu.findPar(v)) return false;
                dsu.Union(u, v);
            }

            if (rightChild[i] != -1) {
                int v = rightChild[i];

                inDegree[v]++;
                if (inDegree[v] > 1) return false;

                if (dsu.findPar(u) == dsu.findPar(v)) return false;
                dsu.Union(u, v);
            }
        }

        // Must be exactly one node with in-degree 0 (root)
        int roots = 0;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) roots++;
        }

        if (roots != 1) return false;

        return dsu.getSize() == 1;
    }
};
