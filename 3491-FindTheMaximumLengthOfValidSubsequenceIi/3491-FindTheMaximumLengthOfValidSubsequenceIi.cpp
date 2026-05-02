// Last updated: 02/05/2026, 22:33:18
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        
        int n = nums.size();

        vector<vector<int>> dp(k, vector<int>(n, 1));


        int longest_valid_subsequence = 1;

        for(int curr = 1; curr < n; curr++){

            for(int prev = 0; prev < curr; prev++){

                int mod = (nums[prev] + nums[curr]) % k;

                dp[mod][curr] = max(dp[mod][curr], 1 + dp[mod][prev]);

                longest_valid_subsequence = max(longest_valid_subsequence, dp[mod][curr]);
            }
        }

        return longest_valid_subsequence;
    }
};