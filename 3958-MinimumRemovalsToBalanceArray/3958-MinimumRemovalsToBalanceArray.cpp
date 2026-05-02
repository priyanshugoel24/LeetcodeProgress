// Last updated: 02/05/2026, 22:32:11
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
       
        int min_elements_to_remove = n;

        for (int i = 0; i < n; ++i) {
            // nums[i] is the new minimum
            long long max_allowed = (long long)nums[i] * k;

            // upper_bound gives first index where element > max_allowed
            int j = upper_bound(nums.begin() + i, nums.end(), max_allowed) - nums.begin();

            // elements to keep: j - i
            // elements to remove: total - (j - i)
            min_elements_to_remove = min(min_elements_to_remove, n - (j - i));
        }

        return min_elements_to_remove;
    }
};
