// Last updated: 02/05/2026, 22:41:46
class Solution {
public:
    int solve(int idx1, int idx2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        int m = nums1.size(), n = nums2.size();

        //base case
        if(idx1 >= m || idx2 >= n){ // either array is finished so no more matching possible
            return 0;
        }

        // if subproblem is already solved
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(nums1[idx1] == nums2[idx2]){

            return dp[idx1][idx2] = 1 + solve(idx1 + 1, idx2 + 1, nums1, nums2, dp);
        }else{

            int option1 = solve(idx1, idx2 + 1, nums1, nums2, dp); // fix pointer of 1st array
            int option2 = solve(idx1 + 1, idx2, nums1, nums2, dp); // fix pointer of 2nd array


            return dp[idx1][idx2] = max(option1, option2);
        }

        
    }

    int solveTab(vector<int>& nums1, vector<int>& nums2){

        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));


        for(int idx1 = m-1; idx1 >= 0; idx1--){

            for(int idx2 = n-1; idx2 >= 0; idx2--){


                if(nums1[idx1] == nums2[idx2]){

                    dp[idx1][idx2] = 1 + dp[idx1 + 1][idx2 + 1];
                }else{

                    int option1 = dp[idx1][idx2 + 1]; // fix pointer of 1st array
                    int option2 = dp[idx1 + 1][idx2]; // fix pointer of 2nd array


                    dp[idx1][idx2] = max(option1, option2);
                }

            }
        }

        return dp[0][0];
    }

    int solveSO(vector<int>& nums1, vector<int>& nums2){

        int m = nums1.size(), n = nums2.size();

        vector<int> prev(n+1, 0);
        vector<int> next(n+1, 0);

        for(int idx1 = m-1 ; idx1 >= 0; idx1--){

            for(int idx2 = n-1; idx2 >= 0; idx2--){


                if(nums1[idx1] == nums2[idx2]){

                    prev[idx2] = 1 + next[idx2 + 1];
                }else{

                    int option1 = prev[idx2 + 1]; // fix pointer of 1st array
                    int option2 = next[idx2]; // fix pointer of 2nd array


                    prev[idx2] = max(option1, option2);
                }


            }

            next = prev;
        }

        return next[0];
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        // int m = nums1.size(), n = nums2.size();
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // return solve(0, 0, nums1, nums2, dp);

        // return solveTab(nums1, nums2);

        return solveSO(nums1, nums2);
    }
};