// Last updated: 02/05/2026, 22:45:48
class Solution {
public:
    int solveTab(int num){
        vector<int> dp(num+1, INT_MAX);

        dp[0] = 0; // for creating 0 we require 0 numbers

        for(int i = 1; i <= num; i++){
            for(int j = 1; j*j <= num ; j++){

                if(i - j*j >= 0 && dp[i - j*j] != INT_MAX){
                    dp[i] = min(dp[i], 1 + dp[i - j*j]);
                }
            }
        }

        return dp[num];
    
    }
    int numSquares(int n) {
        return solveTab(n);
    }
};