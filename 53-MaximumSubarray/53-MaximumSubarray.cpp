// Last updated: 02/05/2026, 22:48:31
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();

        int maxSubarraySum = INT_MIN;
        int currSubarraySum = 0;

        for(int idx = 0; idx < n; idx++){

            // add the curr element to the curr sum
            currSubarraySum += nums[idx];
                       
            maxSubarraySum = max(maxSubarraySum, currSubarraySum);
            
            // if the sum becomes less than zero, discard the sum of the curr subarray
            if(currSubarraySum < 0){
                currSubarraySum = 0;
            }

        }

        return maxSubarraySum;

    }
};