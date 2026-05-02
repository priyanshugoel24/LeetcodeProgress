// Last updated: 02/05/2026, 22:43:05
class Solution {
public:
    bool dfs(vector<vector<int>>& g, vector<int>& colour, int node) {
         
         colour[node] = 1;

         for(auto cur : g[node]) {
            if(colour[cur] == 0 && dfs(g, colour, cur) || colour[cur] == 1) return true;
         }
         
         colour[node] = 2;
         return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
         
         int n = g.size();

         vector<int> colour(n);
         vector<int> result;

         for(int i=0; i<n; i++) {
            if(colour[i] == 2 || !dfs(g, colour, i))
                result.push_back(i);
         }
          
         return result; 
    }
};
