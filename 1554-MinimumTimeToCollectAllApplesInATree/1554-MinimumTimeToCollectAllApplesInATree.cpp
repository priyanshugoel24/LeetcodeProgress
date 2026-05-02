// Last updated: 02/05/2026, 22:39:40
class Solution {
public:
    int dfs(unordered_map<int, vector<int>>& adj, int node, int parent, vector<bool>& hasApple){

        int time = 0;

        for(int &nbr : adj[node]){

            if(nbr == parent) continue;

            int time_from_my_child = dfs(adj, nbr, node, hasApple);

            if(time_from_my_child > 0 || hasApple[nbr]){
                time += time_from_my_child + 2;
            }
        }

        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        unordered_map<int, vector<int>> adj;

        for(auto &edge : edges){

            int u = edge[0], v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int min_time = dfs(adj, 0, -1, hasApple);

        return min_time;
    }
};