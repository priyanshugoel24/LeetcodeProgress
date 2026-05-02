// Last updated: 02/05/2026, 22:47:27
class Solution {
public:
    long long solve(int idx, int buy, vector<int>& prices, int n, vector<vector<int>>& dp){

        if(idx == n) return 0;

        long long profit = 0;

        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }

        if(buy){

            profit = max(-prices[idx] + solve(idx + 1, 0, prices, n, dp), 0 + solve(idx + 1, 1, prices, n, dp));
        }else{

            profit = max(prices[idx] + solve(idx + 1, 1, prices, n, dp), 0 + solve(idx + 1, 0, prices, n, dp));
        }

        return dp[idx][buy] =  profit;
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(0, 1, prices, n, dp);
    }
};