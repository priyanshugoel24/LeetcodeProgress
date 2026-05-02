// Last updated: 02/05/2026, 22:44:28
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();

        vector<vector<int>> dp(n+1, vector<int>(amount + 1, 0)); //tabulation vector
        //dp[i][amt] -> no of ways to make up amount using coins till ith index

        // base case : there is always 1 way to make up 0 amount
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }

        //filling the tabulation matrix
        for(int idx = 1; idx <= n; idx++){

            for(int currAmount = 1; currAmount <= amount; currAmount++){
                
                //option1 : skip the current coin
                int skip = dp[idx -1][currAmount];

                //option 2 : take the current coin
                int take = 0;
                if(coins[idx-1] <= currAmount){
                    take = dp[idx][currAmount - coins[idx-1]];
                }

                //storing the result of both ways
                dp[idx][currAmount] = (long long)take + skip;
            }
        }

        // return no of ways to make up amount using n-1 coins
        return dp[n][amount];
    }
};