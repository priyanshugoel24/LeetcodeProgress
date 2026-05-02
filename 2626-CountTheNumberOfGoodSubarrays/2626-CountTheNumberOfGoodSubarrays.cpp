// Last updated: 02/05/2026, 22:35:31
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        int n = nums.size();
        int left = 0, right = 0;

        long long goodSubarrays = 0;

        unordered_map<int, int> freq; // freq[i] gives freq of numbers in nums

        long long validPairs = 0;

        while(right < n){

            validPairs += freq[nums[right]];
            freq[nums[right]]++;

            while(validPairs >= k){
                goodSubarrays += (n - right);
                freq[nums[left]]--;
                validPairs -= freq[nums[left]];
                left++;
            }

            right++;
        }

        return goodSubarrays;

    }
};