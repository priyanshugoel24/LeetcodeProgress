// Last updated: 02/05/2026, 22:43:14
class Solution {
public:
    int numTilings(int n) {
        int mod = 1e9 + 7;
        if(n == 1 || n == 2) return n;
        vector<int> dp(n+1);

        dp[0] = 1; // 0 ways to tile 2 * 0 board
        dp[1] = 1; // 1 way to tile 2 * 1 board
        dp[2] = 2; // 2 ways to tile 2 * 2 board

        for(int i = 3; i <= n; i++){

            dp[i] = (2 * dp[i-1] % mod + dp[i-3] % mod) % mod ;
        }

        return dp[n] % mod;
    }
};