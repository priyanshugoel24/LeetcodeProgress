// Last updated: 02/05/2026, 22:48:21
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));


        // fill the first row 
        for(int col = 0; col < n; col++){
            if(col >= 1 && obstacleGrid[0][col - 1] == 1){
                dp[0][col] = 0;
                obstacleGrid[0][col] = 1;
            }else if(obstacleGrid[0][col] == 1){
                dp[0][col] = 0;
            }else{
                dp[0][col] = 1;
            }
        }

        for(int row = 0; row < m; row++){
            if(row > 0 && obstacleGrid[row-1][0] == 1){
                dp[row][0] = 0;
                obstacleGrid[row][0] = 1;
            }else if(obstacleGrid[row][0] == 1){
                dp[row][0] = 0;
            }else{
                dp[row][0] = 1;
            }
        }

        for(int row = 1; row < m; row++){
            for(int col = 1; col < n; col++){

                if(obstacleGrid[row][col] == 1){
                    dp[row][col] = 0;
                }else{
                    dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};