// Last updated: 02/05/2026, 22:48:29
class Solution {
public:
    bool solve(int idx, vector<int>& nums, vector<int>& dp){
        int n = nums.size();

        //base case
        if(idx >= n-1){
            return true;
        }

        if(dp[idx] != -1) return dp[idx];

        for(int i = 1; i<=nums[idx]; i++){
            bool next = solve(idx+i, nums,dp);
            if(next) return true;
        }

        return dp[idx] = false;
    }

    bool solveTab(vector<int>& nums){
        int n = nums.size();

        vector<bool> dp(n, false);
        
        dp[0] = true;

        for(int i = 1; i<n; i++){

            for(int j = i-1; j>=0; j--){
                if(dp[j] && j + nums[j] >= i){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n-1];
    }

    bool solveOpt(vector<int>& nums){
        int n = nums.size();

        int maxReachable = 0;

        for(int i = 0; i<n; i++){
            if(i > maxReachable) return false;

            maxReachable = max(maxReachable, i + nums[i]);
        }

        return true;
    }
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        // vector<int> dp(n+1, -1);
        // return solve(0, nums, dp);

        // return solveTab(nums);

        return solveOpt(nums);
    }
};