// Last updated: 02/05/2026, 22:39:45
class Solution {
public:
    int dp[51][51][101];
    int solve(int idx, int searchCost, int maxSoFar, int n, int m, int k){

        int mod = 1e9 + 7;
        if(idx == n){
            if(searchCost == k) return 1;
            return 0;
        }

        if(dp[idx][searchCost][maxSoFar] != -1){
            return dp[idx][searchCost][maxSoFar];
        }

        int result = 0;
        for(int i = 1; i <= m; i++){

            if(i > maxSoFar){

                result = (result +  solve(idx + 1, searchCost + 1, i, n, m, k)) % mod;
            }else{
                result = (result +  solve(idx + 1, searchCost, maxSoFar, n, m, k)) % mod;
            }
        }

        return dp[idx][searchCost][maxSoFar] = result % mod;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0,0, 0, n, m, k);
    }
};