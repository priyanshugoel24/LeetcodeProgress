// Last updated: 02/05/2026, 22:37:43
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int, vector<int>> adj;

        for(auto &edge : edges){

            int u = edge[0], v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, false);

        queue<int> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            visited[node] = true;

            if(node == destination) return true;

            for(auto &nbr : adj[node]){
                
                if(!visited[nbr]){
                    q.push(nbr);
                }
            }
        }

        return false;
    }
};