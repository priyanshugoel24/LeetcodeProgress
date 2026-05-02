// Last updated: 02/05/2026, 22:42:32
class Solution {
public:
    bool checkBipartite(unordered_map<int, vector<int>>& adj, int node, vector<int>& color){

        queue<int> q;
        
        q.push(node);
        color[node] = 1;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int &nbr : adj[curr]){

                if(color[nbr] == color[curr]){
                    return false;
                }

                if(color[nbr] == -1){
                    q.push(nbr);
                    color[nbr] = 1 - color[curr];
                }
            }
        }

        return true;

    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        unordered_map<int, vector<int>> adj;

        for(vector<int>& vec : dislikes){

            int u = vec[0], v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(n + 1, -1);

        for(int i = 1; i <= n; i++){

            if(color[i] == -1){

                if(!checkBipartite(adj, i, color)){
                    return false;
                }
            }
        }

        return true;
    }
};