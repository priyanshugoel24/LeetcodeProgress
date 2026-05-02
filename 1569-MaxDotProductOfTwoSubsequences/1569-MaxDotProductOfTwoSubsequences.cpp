// Last updated: 02/05/2026, 22:39:35
class Solution {
public:
    int solve(int idx_nums1, int idx_nums2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){

        int m = nums1.size(), n = nums2.size();
        
        //base case : idx out of bound
        if(idx_nums1 >= m || idx_nums2 >= n){
            return -1e9;
        }

        //if the subproblem is already solved
        if(dp[idx_nums1][idx_nums2] != -1){
            return dp[idx_nums1][idx_nums2];
        }

        //case1 : just take nums[i] * nums[j]
        int opt1 = nums1[idx_nums1] * nums2[idx_nums2];

        //case2 : take nums[i]*nums[j] and solve for further
        int opt2 = nums1[idx_nums1] * nums2[idx_nums2] + solve(idx_nums1 + 1, idx_nums2 + 1, nums1, nums2, dp);

        //case3 : take only nums[i]
        int opt3 = solve(idx_nums1, idx_nums2 + 1, nums1, nums2, dp);

        //case4 : take only nums[j]
        int opt4 = solve(idx_nums1 + 1, idx_nums2, nums1, nums2, dp);

        //choose the maximum among all
        int maxDotProduct = max({opt1, opt2, opt3, opt4});

        return dp[idx_nums1][idx_nums2] = maxDotProduct;

    }

    int solveTab(vector<int>& nums1, vector<int>& nums2){

        int m = nums1.size(), n = nums2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); //tabulation vector

        for(int i = 0; i<=m; i++){
            dp[i][n] = -1e9;
        }
        for(int j = 0; j <= n; j++){
            dp[m][j] = -1e9;
        }

        for(int idx_nums1 = m - 1; idx_nums1 >= 0; idx_nums1--){

            for(int idx_nums2 = n - 1; idx_nums2 >= 0; idx_nums2--){

                //case1 : just take nums[i] * nums[j]
                int opt1 = nums1[idx_nums1] * nums2[idx_nums2];

                //case2 : take nums[i]*nums[j] and solve for further
                int opt2 = nums1[idx_nums1] * nums2[idx_nums2] + dp[idx_nums1 + 1][idx_nums2 + 1];

                //case3 : take only nums[i]
                int opt3 = dp[idx_nums1][idx_nums2 + 1];

                //case4 : take only nums[j]
                int opt4 = dp[idx_nums1 + 1][idx_nums2];

                //choose the maximum among all
                int maxDotProduct = max({opt1, opt2, opt3, opt4});

                dp[idx_nums1][idx_nums2] = maxDotProduct;
            }
        }

        return dp[0][0];
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        // int m = nums1.size(), n = nums2.size();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // return solve(0, 0, nums1, nums2, dp);

        return solveTab(nums1, nums2);
    }
};