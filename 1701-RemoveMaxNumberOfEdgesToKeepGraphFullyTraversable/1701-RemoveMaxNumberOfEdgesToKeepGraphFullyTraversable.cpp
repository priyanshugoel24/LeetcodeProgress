// Last updated: 02/05/2026, 22:39:08
class Solution {
public:
    class DSU {
    vector<int> parent;
    vector<int> rank;
    int size;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1); // rank initialized to 0
        size = n;          // initialize size

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int x) {
        if (parent[x] != x) {
            parent[x] = findPar(parent[x]); // path compression
        }
        return parent[x];
    }

    void Union(int x, int y) {
        int par_x = findPar(x);
        int par_y = findPar(y);

        if (par_x == par_y) return; // already in same component

        if (rank[par_x] > rank[par_y]) {
            parent[par_y] = par_x;
        } else if (rank[par_x] < rank[par_y]) {
            parent[par_x] = par_y;
        } else {
            parent[par_y] = par_x;
            rank[par_x]++;
        }

        size--; // reduce size when two sets are merged
    }

    int getSize() {
        return size;
    }
};

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        DSU dsu_alice(n);
        DSU dsu_bob(n);

        int edges_removed = 0;

        sort(edges.begin(), edges.end(), [&](vector<int>& a, vector<int>& b){
            return a[0] > b[0];
        });       

        for(int i = 0; i < edges.size(); i++){

            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];

            // join nodes which can be traversed by both
            if(type == 3){

                if((dsu_alice.findPar(u) == dsu_alice.findPar(v)) || (dsu_bob.findPar(u) == dsu_bob.findPar(v))){
                    edges_removed++;
                }
                
                dsu_alice.Union(u, v);
                dsu_bob.Union(u, v);
            }

            //for type 2 edges add to bob but first check if it is necessary to add it or not
            if(type == 2){
                
                if(dsu_bob.findPar(u) == dsu_bob.findPar(v)){
                    edges_removed++;
                }else{
                    dsu_bob.Union(u, v);
                }
            }

            //same for type 1 edges
            if(type == 1){

                if(dsu_alice.findPar(u) == dsu_alice.findPar(v)){
                    edges_removed++;
                }else{
                    dsu_alice.Union(u, v);
                }
            }

        }

        // now check for both alice's and bob's graph if there are multiple components that means that full traversal is not possible

        if(dsu_alice.getSize() != 1 || dsu_bob.getSize() != 1){
            return -1;
        }

        // return the maximum no of edges we can remove
        return edges_removed;

    }
};