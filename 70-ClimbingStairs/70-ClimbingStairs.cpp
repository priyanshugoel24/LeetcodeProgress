// Last updated: 02/05/2026, 22:48:18
class Solution {
public:
    int solve(int n){
        if(n == 1) return 1;
        if(n == 2) return 2;
        vector<int> dp(n+1, 0);
        
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
        
    }
    int climbStairs(int n) {

        

        return solve(n);
        
    }
};