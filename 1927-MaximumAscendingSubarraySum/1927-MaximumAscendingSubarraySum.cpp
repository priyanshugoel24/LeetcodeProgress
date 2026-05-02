// Last updated: 02/05/2026, 22:38:19
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int maxSum = nums[0], n = nums.size(), sum = nums[0];

        for(int i = 1; i<n; i++){
            if(nums[i-1] < nums[i]){
                sum += nums[i];
                maxSum = max(maxSum, sum);
            }else{
                sum = nums[i];
                maxSum = max(maxSum, nums[i]);
            }
           
    
        }

        return maxSum;
        
    }
};