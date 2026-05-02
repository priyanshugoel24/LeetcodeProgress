// Last updated: 02/05/2026, 22:40:20
class DisjointSet {
    
public:
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            
        }
    }

    int findUPar(int x) {
        if (parent[x] != x) {
            parent[x] = findUPar(parent[x]);
        }
        return parent[x];
    }

    void unionbyRank(int x, int y) {
        int rootx = findUPar(x);
        int rooty = findUPar(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                parent[rootx] = rooty;
            } else if (rank[rootx] > rank[rooty]) {
                parent[rooty] = rootx;
            } else {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        DisjointSet ds(n);

        int extraEdges = 0;

        for(int i = 0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            if(ds.findUPar(u) == ds.findUPar(v)) extraEdges++;
            else ds.unionbyRank(u , v);
        }

        int connectedComponents = 0;
        for(int i = 0; i<n; i++){
            if(ds.parent[i] == i) connectedComponents++;
        }

        int ans = connectedComponents -1;
        if(extraEdges >= ans) return ans;
        else return -1;


        
    }
};