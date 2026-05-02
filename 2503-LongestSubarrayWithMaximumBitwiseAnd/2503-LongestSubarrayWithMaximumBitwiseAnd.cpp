// Last updated: 02/05/2026, 22:35:53
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();

        int longest_subarray_length = 1;
        int max_bitwise_AND = *max_element(nums.begin(), nums.end());

        int i = 0;

        while(i < n){

            int curr_num = nums[i];

            if(curr_num < max_bitwise_AND){
                i++;
                continue;
            }       

            int j = i;

            while(j < n && nums[j] == max_bitwise_AND){
                j++;
            } 

            int window_length = j - i ;
            longest_subarray_length = max(longest_subarray_length, window_length);
            
            i = j;
        }
        return longest_subarray_length;
    }
};