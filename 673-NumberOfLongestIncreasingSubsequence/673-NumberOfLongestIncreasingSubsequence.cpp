// Last updated: 02/05/2026, 22:43:50
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> cnt(n, 1); // count of no of lis at length i
        int maxLen = 1;

        for(int i = 1; i < n; i++){

            for(int j = 0; j < i; j++){

                if(nums[i] - nums[j] > 0 && 1 + dp[j] > dp[i]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                    cnt[i] = cnt[j];
                }else if(nums[i] - nums[j] > 0 && 1 + dp[j] == dp[i]){
                    cnt[i] += cnt[j];
                }

                maxLen = max(maxLen, dp[i]);
            }
        }

        int result = 0;

        for(int i = 0; i < n; i++){
            if(dp[i] == maxLen){
                result += cnt[i];
            }
        }

        
        return result;

    
    }
};