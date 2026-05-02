// Last updated: 02/05/2026, 22:32:32
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        
        int n = nums.size();

        int subsequences_to_remove = n / 3;

        long long max_median_sum = 0;

        sort(begin(nums), end(nums));

        int lastMaxMedian = n / 3;

        for(int i = lastMaxMedian; i < n; i += 2){

            max_median_sum += nums[i];
        }

        return max_median_sum;
    }
};