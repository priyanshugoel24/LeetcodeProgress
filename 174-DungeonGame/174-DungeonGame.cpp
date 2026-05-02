// Last updated: 02/05/2026, 22:46:46
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>>& dp){

        int m = dungeon.size();
        int n = dungeon[0].size();

        // base case : if reached destination
        if(i == m - 1 && j == n - 1){

            if(dungeon[i][j] > 0){
                return 1;
            }

            return abs(dungeon[i][j]) + 1;
        }

        // base case : index out of bounds
        if(i >= m || j >= n){

            return 1e9;
        }

        // if the subproblem is already solved
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right_step = solve(i, j + 1, dungeon, dp);
        int down_step = solve(i+1, j, dungeon, dp);

        int result = min(right_step, down_step) - dungeon[i][j];

        (result > 0) ? (dp[i][j] = result) : (dp[i][j] = 1);

        return dp[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int m = dungeon.size();
        int n = dungeon[0].size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(0, 0, dungeon, dp);
    }
};