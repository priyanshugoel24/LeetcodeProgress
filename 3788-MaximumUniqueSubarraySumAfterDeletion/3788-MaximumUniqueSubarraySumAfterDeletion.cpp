// Last updated: 02/05/2026, 22:32:31
class Solution {
public:
    int maxSum(vector<int>& nums) {
        
        int n = nums.size();

        sort(begin(nums), end(nums));

        int i = 0; 

        int max_subarray_sum = 0;

        while(i < n){

            //skip the negative and zero elements
            while(i < n && nums[i] <= 0){
                i++;
            }

            if(i == n){
                return nums[n - 1];
            }

            int curr_num = nums[i];

            max_subarray_sum += curr_num;

            while(i < n && nums[i] == curr_num){
                i++;
            }
        }

        return max_subarray_sum;

    }
};