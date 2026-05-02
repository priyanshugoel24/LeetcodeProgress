// Last updated: 02/05/2026, 22:46:35
class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        int prev2 = 0;
        int prev1 = nums[0];

        for(int i = 1; i<n; i++){
            int incl = prev2 + nums[i];
            int excl = prev1 + 0;

            int ans = max(incl, excl);

            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;
        
    }
};