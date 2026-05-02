// Last updated: 02/05/2026, 22:46:41
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        vector<vector<int>> next(2, vector<int>(k + 1, 0));

        for(int idx = n - 1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                for(int limit = 1; limit <= k; limit++){                   

                    if(buy){
                        
                        curr[1][limit] = max(-prices[idx] + next[0][limit], 0 + next[1][limit]);  

                    }else{                

                        curr[0][limit] = max(prices[idx] + next[1][limit - 1], 0 + next[0][limit]); 

                    }                   

                }

                
            }

            next = curr;
        }

        return next[1][k];
    }
};