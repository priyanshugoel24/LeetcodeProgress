// Last updated: 02/05/2026, 22:47:26
class Solution {
public:
    int solveSO(vector<int>& prices){

        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        for(int idx = n - 1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                for(int limit = 1; limit <= 2; limit++){                   

                    if(buy){
                        
                        curr[1][limit] = max(-prices[idx] + next[0][limit], 0 + next[1][limit]);  

                    }else{                

                        curr[0][limit] = max(prices[idx] + next[1][limit - 1], 0 + next[0][limit]); 

                    }                   

                }

                next = curr;
            }
        }

        return next[1][2];
        
    }
    int maxProfit(vector<int>& prices) {
        
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        // for(int idx = n - 1; idx >= 0; idx--){
        //     for(int buy = 0; buy <= 1; buy++){
        //         for(int limit = 1; limit <= 2; limit++){                   

        //             if(buy){
                        
        //                 dp[idx][1][limit] = max(-prices[idx] + dp[idx + 1][0][limit], 0 + dp[idx + 1][1][limit]);  

        //             }else{                

        //                 dp[idx][0][limit] = max(prices[idx] + dp[idx + 1][1][limit - 1], 0 + dp[idx + 1][0][limit]); 

        //             }                   

        //         }
        //     }
        // }

        // return dp[0][1][2];

        return solveSO(prices);
    }
};