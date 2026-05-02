// Last updated: 02/05/2026, 22:33:16
class Solution {
public:
    int bfs(unordered_map<int, vector<int>>& adj, int n){

        queue<pair<int, int>> q;
        vector<bool> visited(n, false);
        q.push({0, 0});

        while(!q.empty()){

           auto [node, dist] = q.front();
           q.pop();
           visited[node] = true;

           if(node == n - 1){
            return dist;
           }

           for(auto& nbr : adj[node]){
            if(!visited[nbr])
                q.push({nbr, dist + 1});
           }
        }

        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        vector<int> result;

        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < n - 1; i++){
            adj[i].push_back(i + 1);
        }

        for(int i = 0; i < queries.size(); i++){

            int u = queries[i][0];
            int v = queries[i][1];

            adj[u].push_back(v);

            int dist = bfs(adj, n);
            result.push_back(dist);

        }

        return result;
    }
};