// Last updated: 02/05/2026, 22:36:21
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int size_of_array = nums.size();

        long long num_of_zero_filled_subarrays = 0;

        long long curr_length_zero_filled_subarray = 0;

        for(size_t idx = 0; idx < size_of_array; idx++){

            if(nums[idx] == 0){

                while(idx < size_of_array && nums[idx] == 0){

                    curr_length_zero_filled_subarray++;
                    idx++;
                }

                num_of_zero_filled_subarrays += ((curr_length_zero_filled_subarray)*(curr_length_zero_filled_subarray + 1)) / 2;

                curr_length_zero_filled_subarray = 0;
            }
            
        }

        return num_of_zero_filled_subarrays;
    }
};