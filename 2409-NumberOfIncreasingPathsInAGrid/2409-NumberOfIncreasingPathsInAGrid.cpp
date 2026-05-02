// Last updated: 02/05/2026, 22:36:26
class Solution {
public:
    bool isSafe(vector<vector<int>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size();

        if(i >= 0  && i < m && j >= 0 && j < n){
            return true;
        }

        return false;
    }
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        int mod = 1e9 + 7;
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int paths = 1;

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(auto dir : directions){

            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(isSafe(grid,new_i, new_j) && grid[new_i][new_j] > grid[i][j]){
                paths = (paths + solve(grid, new_i, new_j, dp)) % mod;
            }
        }

        return dp[i][j] =  paths;
    }

    int countPaths(vector<vector<int>>& grid) {
        int mod = 1e9 + 7;
       int m = grid.size(), n = grid[0].size();

       vector<vector<int>> dp(m, vector<int>(n, -1));
       int result = 0;

       for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){

            result = (result + solve(grid, i, j, dp)) % mod;
        }
       }

       return result;
    }
};