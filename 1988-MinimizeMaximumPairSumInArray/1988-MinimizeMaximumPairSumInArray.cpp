// Last updated: 02/05/2026, 22:38:09
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int maxSum = INT_MIN;

        int n = nums.size();

        int l = 0, r = n-1;

        while(l < r){

            int curr_sum = nums[l] + nums[r];

            maxSum = max(maxSum, curr_sum);

            l++, r--;
        }

        return maxSum;
    }
};