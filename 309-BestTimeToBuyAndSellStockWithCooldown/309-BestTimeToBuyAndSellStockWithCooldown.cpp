// Last updated: 02/05/2026, 22:45:37
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if(n == 0 || n == 1){
            return 0;
        }

        vector<int> dp(n, 0);

        //dp[i]= max profit till day i

        dp[0] = 0;
        dp[1] = max(prices[1] - prices[0], 0);

        for(int i = 2; i < n; i++){
            dp[i] = dp[i-1];

            for(int j = 0; j <= i - 1; j++){
                int today_profit = prices[i] - prices[j];

                int prev_profit =  (j >= 2 ? dp[j-2] : 0); // j-1 day is cooldown period


                dp[i] = max(dp[i], today_profit + prev_profit);
            }
        }

        return dp[n-1];
    }
};