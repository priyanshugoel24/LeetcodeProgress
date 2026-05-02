// Last updated: 02/05/2026, 22:37:26
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<int> indegree(n + 1, 0);

        unordered_map<int, vector<int>> adj;
        for(auto& relation : relations){

            int u = relation[0], v = relation[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0){
                q.push(i);
                dp[i] = time[i - 1];
            }
        }

        while(!q.empty()){

          int course = q.front();
          q.pop();

          for(auto& nbr : adj[course]){

            dp[nbr] = max(dp[nbr], dp[course] + time[nbr - 1]);
            indegree[nbr]--;
            
            if(indegree[nbr] == 0){
                q.push(nbr);
            }
          }
        }

        return *max_element(dp.begin(), dp.end());
        
    }
};