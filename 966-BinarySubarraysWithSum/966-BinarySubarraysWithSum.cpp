// Last updated: 02/05/2026, 22:42:15
class Solution {
public:
    int findSubarraysWithGivenSum(vector<int>& nums, int size_of_array, int goal){
        
        // we cannot make any negative sum using whole numbers
        if(goal < 0) return 0;

        int left = 0, right = 0;

        int subarrays_with_given_sum = 0;
        int curr_subarray_sum = 0;

        while(right < size_of_array){
            
            curr_subarray_sum += nums[right];

            while(left <= right && curr_subarray_sum > goal){
                curr_subarray_sum -= nums[left];
                left++;
            }           

            subarrays_with_given_sum += right - left + 1;

            right++;
        }

        return subarrays_with_given_sum;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int size_of_array = nums.size();

        int num_of_valid_subarrays = findSubarraysWithGivenSum(nums, size_of_array, goal) - findSubarraysWithGivenSum(nums, size_of_array, goal - 1);


        return num_of_valid_subarrays;
    }
};