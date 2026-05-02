// Last updated: 02/05/2026, 22:40:35
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();

        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

        for(int i = 1; i <= n; i++){

            for(int coins = 0; coins <= k ; coins++){

                int sum = 0;

                for(int currCoins = 0; currCoins <= min((int)piles[i-1].size(), coins); currCoins++){
                    if(currCoins > 0) sum += piles[i-1][currCoins-1];

                    dp[i][coins] = max(dp[i][coins], sum + dp[i-1][coins - currCoins]);
                }
            }
        }

        return dp[n][k];
    }
};