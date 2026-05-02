// Last updated: 02/05/2026, 22:47:52
class Solution {
public:
    int solveMem(int n, vector<int>& dp){
        //base case
        if(n <= 1){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }
        
        int ans = 0;

        //take all i as root nodes
        for(int i = 1; i<=n; i++){
            ans += solveMem(i-1, dp) * solveMem(n-i, dp);

        }

        return dp[n] = ans;
    }

    int solveTab(int n){
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;

        //i is no of nodes
        for(int i = 2; i<=n; i++){
            //j is the root node
            for(int j = 1; j<=i; j++){
                dp[i] += dp[j-1]*dp[i-j];
            }
        }

        return dp[n];
    }
    int numTrees(int n) {

        /*vector<int> dp(n+1, -1);
        return solveMem(n, dp);*/

        return solveTab(n);
       
        
    }
};