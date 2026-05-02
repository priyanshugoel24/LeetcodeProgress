// Last updated: 02/05/2026, 22:34:11
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size(); //size of the array

        int maxElement = *max_element(nums.begin(), nums.end()); // maximum element in nums array

        long long countOfMaxElement = 0; //freq of maximum element in current window
        long long subarrays = 0; // no of valid subarrays

        int left = 0, right = 0; // left and right pointers of sliding window

        while(right < n){

            //case : element at right pointer is equal to max element, so update frequency
            if(nums[right] == maxElement){
                countOfMaxElement++;
            }

            //case : while the count of max element is equal to k we can shrink the window
            while( left <= right && countOfMaxElement == k){
                
                if(nums[left] == maxElement){
                    countOfMaxElement--;
                }

                left++;
            }

            // update the count of valid subarrays
            subarrays += left;

            right++;

        }

        return subarrays;
    }
};