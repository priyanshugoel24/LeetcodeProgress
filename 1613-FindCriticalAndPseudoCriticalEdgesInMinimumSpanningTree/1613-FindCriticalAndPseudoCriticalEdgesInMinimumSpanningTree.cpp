// Last updated: 02/05/2026, 22:39:26
class Solution {
public:
    int N;
    class DSU{

        vector<int> parent;
        vector<int> rank;

        public:
        DSU(int n){

            parent.resize(n);
            rank.resize(n);

            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }

        int findPar(int x){

            if(parent[x] != x){
                parent[x] = findPar(parent[x]);
            }

            return parent[x];
        }

        void Union(int x, int y){

            int par_x = findPar(x);
            int par_y = findPar(y);

            if(par_x == par_y) return;

            if(rank[par_x] > rank[par_y]){
                parent[par_y] = par_x;
            }else if(rank[par_x] < rank[par_y]){
                parent[par_x] = par_y;
            }else{
                parent[par_y] = par_x;
                rank[par_x]++;
            }
        }
    };
    int kruskal(vector<vector<int>>& vec, int skip_edge, int add_edge){

        DSU dsu(N);
        int sum = 0;

        if(add_edge != -1){
            dsu.Union(vec[add_edge][0], vec[add_edge][1]);
            sum += vec[add_edge][2];
        }

        for(int i = 0; i < vec.size(); i++){

            if(i == skip_edge) continue;

            int u = vec[i][0];
            int v = vec[i][1];
            int wt = vec[i][2];

            int par_u = dsu.findPar(u);
            int par_v = dsu.findPar(v);

            if(par_u != par_v){
                dsu.Union(u, v);
                sum += wt;
            }
        }

        for(int i = 0; i < N ; i++){

            if(dsu.findPar(i) != dsu.findPar(0)){
                return 1e9;
            }
        }


        return sum;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        N = n;
        for(int i = 0; i < edges.size(); i++){

            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });

        int mst_wt = kruskal(edges, -1, -1);

        vector<int> critical;
        vector<int> pseudo_critical;

        for(int i = 0; i < edges.size(); i++){

            if(kruskal(edges, i, -1) > mst_wt){
                critical.push_back(edges[i][3]);
            }else if(kruskal(edges, -1, i) == mst_wt){
                pseudo_critical.push_back(edges[i][3]);
            }
        }

       return {critical, pseudo_critical};


    }
};