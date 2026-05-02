// Last updated: 02/05/2026, 22:36:16
class Solution {
public:
    bool solve(int idx, vector<int>& nums, vector<int>& dp){

        int n = nums.size();
        
        //base case : successfully partitioned whole array
        if(idx == n){
            return true;
        }

        //if subproblem is already solved
        if(dp[idx] != -1){
            return dp[idx];
        }

        bool validPartionExists = false;

        // case 1 : 2 equal elements subarray
        if(idx + 1 < n && nums[idx] == nums[idx + 1]){
            validPartionExists = validPartionExists || solve(idx + 2, nums, dp);
        }

        //3 elements subarray
        //case 2 : 3 equal elements subarray
        if(idx + 2 < n && nums[idx] == nums[idx + 1] && nums[idx + 1] == nums[idx + 2]){
            validPartionExists = validPartionExists || solve(idx + 3, nums, dp);
        }
        //case 3 : 3 consecutive elements subarray
        else if(idx + 2 < n && nums[idx] + 1 == nums[idx + 1] && nums[idx + 1] + 1 == nums[idx + 2]){
            validPartionExists = validPartionExists || solve(idx + 3, nums, dp);
        }

        return dp[idx] = validPartionExists;

    }

    bool solveTab(vector<int>& nums){

        int n = nums.size();
        vector<bool> dp(n + 1, false); //tabulation array
        //dp[idx] -> till idx in nums have we found valid partition 

        dp[0] = true; 

        for(int idx = 2; idx <= n; idx++){

            bool validPartitionExists = false;

            if(nums[idx - 1] == nums[idx - 2]){
                validPartitionExists = validPartitionExists || dp[idx - 2];
            }

            if( idx - 3 >= 0 && nums[idx - 1] == nums[idx - 2] && nums[idx - 1] == nums[idx - 3]){
                validPartitionExists = validPartitionExists || dp[idx - 3];
            }
            else if(idx - 3 >= 0 && nums[idx - 1] == 1 + nums[idx - 2] && nums[idx -2] == nums[idx - 3] + 1){
                validPartitionExists = validPartitionExists || dp[idx - 3];
            }

            dp[idx] = validPartitionExists;
        }

        return dp[n];
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n + 1, -1); // memoization array
        // return solve(0, nums, dp);

        return solveTab(nums);
    }
};