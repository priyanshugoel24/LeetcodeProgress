// Last updated: 02/05/2026, 22:33:19
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        int n = nums.size();

        //3 options for valid subsequences
        //1 : all odd
        // 2 : all even
        // 3 : alternating odd and even

        int odd_subsequence_length = 0;
        int even_subsequence_length = 0;
        int alternating_subsequence_length = 1;

        for(int i = 0; i < n; i++){

            if(nums[i] % 2 == 0){
                even_subsequence_length++;
            }else{
                odd_subsequence_length++;
            }
        }

        int prev_parity = nums[0] % 2;

        for(int i = 1; i < n; i++){

            int curr_parity = nums[i] % 2;

            if(curr_parity != prev_parity){
                alternating_subsequence_length++;
                prev_parity = curr_parity;
            }
        }

        int longest_valid_subsequence = max({odd_subsequence_length, even_subsequence_length, alternating_subsequence_length});

        return longest_valid_subsequence;
    }
};