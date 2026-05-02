// Last updated: 02/05/2026, 22:36:35
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        long long total_importance = 0LL;

        vector<int> degree(n, 0);

        for(auto& road : roads){

            int u = road[0], v = road[1];
            degree[u]++;
            degree[v]++;
        }

        sort(degree.begin(), degree.end());

        for(int i = 0; i < n; i++){

            long long curr_importance = (long long)(i + 1) * degree[i];
            total_importance += curr_importance;
        }

        return total_importance;
    }
};