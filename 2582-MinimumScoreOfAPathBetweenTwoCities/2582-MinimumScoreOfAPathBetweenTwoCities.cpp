// Last updated: 02/05/2026, 22:35:38
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, vector< pair<int, int> > > adj;

        for(auto &road : roads){

            int u = road[0], v = road[1], dist = road[2];

            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }

        vector<bool> visited(n + 1, false);

        int minimum_score = 1e9;

        queue< pair<int, int> > q;
        q.push({1, 1e9});


        while(!q.empty()){

            auto [node, dist] = q.front();
            q.pop();

            visited[node] = true;

            minimum_score = min(minimum_score, dist);

            for(auto& [nbr, d] : adj[node]){

                if(!visited[nbr]){

                    q.push({nbr, d});
                }
            }
        }

        return minimum_score;
    }
};