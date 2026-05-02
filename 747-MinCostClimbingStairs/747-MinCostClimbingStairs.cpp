// Last updated: 02/05/2026, 22:43:32
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        int prev1 = cost[0];
        int prev2 = cost[1];

        int ans;

        for(int i = 2; i<n; i++){

            ans = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = ans;

        }

        return min(prev1, prev2);
        
    }
};