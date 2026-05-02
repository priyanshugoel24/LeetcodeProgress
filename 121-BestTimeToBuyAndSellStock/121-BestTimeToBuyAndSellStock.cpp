// Last updated: 02/05/2026, 22:47:28
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buyPrice = prices[0];
        int maxPossibleProfit = 0;

        for(int idx = 1; idx < prices.size(); idx++){

            if(prices[idx] < buyPrice){
                buyPrice = prices[idx];
            }
            else if(prices[idx] - buyPrice > maxPossibleProfit){
                maxPossibleProfit = prices[idx] - buyPrice;
            }
        }

        return maxPossibleProfit;
    }
};