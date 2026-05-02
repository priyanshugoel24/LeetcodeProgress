// Last updated: 02/05/2026, 22:46:25
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int minLength = INT_MAX;

        int curr_sum = 0;

        int l = 0, r = 0;

        while(r < n){

            curr_sum += nums[r];

            //case 1 : sum is more than target
            while(curr_sum >= target){

               minLength = min(minLength, r - l + 1);
               curr_sum -= nums[l];
               l++;
                
            }

            r++;

        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};