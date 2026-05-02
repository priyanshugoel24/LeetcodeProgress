// Last updated: 02/05/2026, 22:48:22
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int row = 0; row < m; row++){
            
            for(int col = 0; col < n; col++){

                if(row == 0 && col == 0){
                    dp[row][col] = 1; // as there is always one unique path to reach the starting point
                    continue;
                }

                // case 1 : reached dp[row][col] from up
                int up = 0;
                if(row > 0){
                    up = dp[row - 1][col];
                }

                // case 2 : reached dp[row][col] from left
                int left = 0;
                if(col > 0){
                    left = dp[row][col - 1];
                }

                // no of ways to reach [row][col] will be total from up and left
                dp[row][col] = up + left;
            }
        }

        return dp[m - 1][n - 1];
    }
};