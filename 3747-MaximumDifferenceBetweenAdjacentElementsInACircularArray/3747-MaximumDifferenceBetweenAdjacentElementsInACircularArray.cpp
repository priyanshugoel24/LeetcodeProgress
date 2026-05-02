// Last updated: 02/05/2026, 22:32:39
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        
        int n = nums.size();

        int max_diff = abs(nums[0] - nums[n - 1]);

        for(int i = 0; i < n - 1; i++){

            max_diff = max(max_diff, abs(nums[i] - nums[i + 1]) ) ;
        }

        return max_diff;
    }
};