// Last updated: 02/05/2026, 22:36:28
class Solution {
public:

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

    int find(int x){

        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void Union(int x, int y){

        int par_x = find(x);
        int par_y = find(y);

        if(par_x == par_y) return;

        if(rank[par_x] < rank[par_y]){
            parent[par_x] = par_y;
        }else if(rank[par_x] > rank[par_y]){
            parent[par_y] = par_x;
        }else{
            parent[par_y] = par_x;
            rank[par_x]++;
        }
    }
};
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        //initalize dsu structure
        DSU dsu(n);

        // make components 
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            dsu.Union(u, v);
        }

        // map for storing size of component wrt to parent
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++){

            int par_i = dsu.find(i);
            mp[par_i]++;
        }

        // for every component multiply its no of nodes with remaning components nodes

        long long unReachablePairs = 0;
        long long remainingNodes = n;

        for(auto &it : mp){

            long long size = it.second;

            unReachablePairs += (size) * (remainingNodes - size);

            remainingNodes -= size;
        }

        return unReachablePairs;
    }
};