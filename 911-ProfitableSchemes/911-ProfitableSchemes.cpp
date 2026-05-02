// Last updated: 02/05/2026, 22:42:34
class Solution {
public:
    int solve(int idx, int currProfit, int n, int minProfit, vector<int>& group, vector<int>& profit, vector<vector<vector<int>>>& dp){
        int mod = 1e9 + 7;
        //base case
        if(idx == profit.size()){
            if(currProfit >= minProfit){
                return 1;
            }else{
                return 0;
            }
        }

        //if the subproblem is already solved
        if(dp[idx][currProfit][n] != -1){
            return dp[idx][currProfit][n];
        }

        //option1 : don't commit the current crime
        int notCommit = (solve(idx+1, currProfit, n, minProfit, group, profit, dp)) % mod;
        
        //option2 : commit the crime if you have enough members
        int commit = 0;
        if(n - group[idx] >= 0){
            commit = solve(idx+1, currProfit + profit[idx], n - group[idx], minProfit, group, profit, dp) % mod;
        }

        int possibleSchemes = (commit + notCommit) % mod;

        return dp[idx][currProfit][n] = possibleSchemes % mod;
    }

    int solveTab(int n, int minProfit, vector<int>& group, vector<int>& profit){
        int mod = 1e9 + 7;
        int totalCrimes = profit.size();

        // dp[idx][currProfit][nMembers]
        vector<vector<vector<int>>> dp(totalCrimes + 1,
            vector<vector<int>>(minProfit + 1, vector<int>(n + 1, 0)));

        // Base case: when idx == profit.size() and currProfit >= minProfit
        for (int members = 0; members <= n; members++) {
            dp[totalCrimes][minProfit][members] = 1; // Only one way (do nothing)
        }

        for (int idx = totalCrimes - 1; idx >= 0; idx--) {
            for (int currProfit = minProfit; currProfit >= 0; currProfit--) {
                for (int membersLeft = 0; membersLeft <= n; membersLeft++) {

                    // Not committing the current crime
                    int notCommit = dp[idx + 1][currProfit][membersLeft];

                    // Committing the current crime if we have enough members
                    int commit = 0;
                    if (membersLeft >= group[idx]) {
                        int newProfit = min(minProfit, currProfit + profit[idx]);
                        commit = dp[idx + 1][newProfit][membersLeft - group[idx]];
                    }

                    dp[idx][currProfit][membersLeft] = (commit + notCommit) % mod;
                }
            }
        }

        return dp[0][0][n];
    
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int profit_length = profit.size();
        int maxProfit = accumulate(profit.begin(), profit.end(), 0);
        
        // vector<vector<vector<int>>> dp(profit_length+1, vector<vector<int>>(maxProfit+1, vector<int>(n+1, -1)));
        
        // return solve(0, 0, n, minProfit, group, profit, dp);

        return solveTab(n, minProfit, group, profit);
        
    }
};