// Last updated: 02/05/2026, 22:36:31
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        int n = nums.size();

        long long subarrays = 0; // no of subarrays with score < k
        long long currSum = 0; // sum of curr window in the array

        int l = 0, r = 0; // left and right pointers of window

        while( r < n){

            //update sum of the current window
            currSum += nums[r];

            //check the score of the current window
            //if the score has exceeded k shrink the window
            while(l <= r && currSum * ( r - l + 1 ) >= k){
                currSum -= nums[l];
                l++;
            }

            //else curr window is valid subarray so all the subarrays in that window will also be valid subarray
            subarrays += (r - l + 1);

            //increase the window size
            r++;

        }

        return subarrays;

    }
};