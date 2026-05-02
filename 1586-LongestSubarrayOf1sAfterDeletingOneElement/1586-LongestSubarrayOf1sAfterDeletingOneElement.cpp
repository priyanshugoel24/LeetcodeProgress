// Last updated: 02/05/2026, 22:39:29
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int size_of_array = nums.size();
        int flips_allowed = 1;

        int longest_ones_length = 0; // max no of consecutive ones with k flips allowed

        // two pointers for traversing the array
        int left = 0, right = 0;

        while(right < size_of_array){
            
            if(nums[right] == 0){
                flips_allowed--;
            }

            // check if it is zero and we have used all our flips so shrink the window
            while (flips_allowed < 0) {
                if (nums[left] == 0) {
                    flips_allowed++;    // reclaim a flip when we drop a zero
                }
                left++;
            }

            // get the length of the current valid window
            int curr_ones_length = right - left + 1;

            // update the max length of the valid window
            longest_ones_length = max(longest_ones_length, curr_ones_length);
            
            // increment the right pointer
            right++;
        }

        // return the longest no of consecutive ones in the array
        return longest_ones_length - 1;
    }
};