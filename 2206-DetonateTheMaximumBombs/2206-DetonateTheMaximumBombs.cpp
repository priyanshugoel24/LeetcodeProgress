// Last updated: 02/05/2026, 22:37:17
class Solution {
public:
    int dfs(int node, unordered_map<int, vector<int>>& adj, vector<bool>& visited){

        int count = 1;
        visited[node] = true;

        for(auto& nbr : adj[node]){

            if(!visited[nbr]){
                count += dfs(nbr, adj, visited);
            }
        }

        return count;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size();

        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < n; i++){
            
            for(int j = i + 1; j < n; j++){

                int x1 = bombs[i][0];
                int y1 = bombs[i][1];
                int r1 = bombs[i][2];

                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                int r2 = bombs[j][2];

                long long dx = x1 - x2;
                long long dy = y1 - y2;

                if (dx*dx + dy*dy <= 1LL * r1 * r1) adj[i].push_back(j);
                if (dx*dx + dy*dy <= 1LL * r2 * r2) adj[j].push_back(i);
            }
        }

        int max_bombs = 0;

        for(int i = 0; i < n; i++){

            vector<bool> visited(n, false);
            int bombs_detonated = dfs(i, adj, visited);
            
            max_bombs = max(max_bombs, bombs_detonated);
        }

        return max_bombs;


    }
};