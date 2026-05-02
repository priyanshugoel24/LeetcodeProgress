// Last updated: 02/05/2026, 22:44:38
class Solution {
public:
    int solve(int left, int right, vector<int>& nums, vector<vector<int>>& dp){
        
        //base case
        if( left > right){ // nums array is traversed completely
            return 0;
        }

        if( left == right){
            return nums[left];
        }

        // if the subproblem is already solved
        if(dp[left][right] != -1){
            return dp[left][right];
        }

        //if you take from left and expect min result for yourself after player 2 has played
        int take_left = nums[left] + min(solve(left+2, right, nums, dp) , solve(left + 1, right - 1, nums, dp));

        //if you take from right and expect min result for yourself after player2 has played
        int take_right = nums[right] + min(solve(left, right-2, nums, dp), solve(left + 1, right - 1, nums, dp));

        //player 1 chooses the max score
        int p1_max_score = max(take_left, take_right);

        return dp[left][right] =  p1_max_score;
    }

    int solveTab(vector<int>& nums){

        int n = nums.size();
        
        vector<vector<int>> dp(n + 1 , vector<int>(n + 1, 0));

        // base case : if at the same point nums[i] would be the max score
        for(int i = 0; i < n; i++){
            dp[i][i] = nums[i];
        }

        for (int length = 2; length <= n; length++) {
            for (int left = 0; left <= n - length; left++) {
                int right = left + length - 1;

                int take_left = nums[left];
                if (left + 2 <= right) take_left += min(dp[left + 2][right], dp[left + 1][right - 1]);
                else if (left + 1 <= right) take_left += dp[left + 1][right - 1];

                int take_right = nums[right];
                if (left <= right - 2) take_right += min(dp[left][right - 2], dp[left + 1][right - 1]);
                else if (left <= right - 1) take_right += dp[left + 1][right - 1];

                dp[left][right] = max(take_left, take_right);
            }
        }

        return dp[0][n-1];


    }
    bool predictTheWinner(vector<int>& nums) {
        
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1)); // memoization to store results 

        //total score possible 
        int total_score = accumulate(nums.begin(), nums.end(), 0);

        // int p1_score = solve(0, n-1 , nums, dp); // max score by player 1
        int p1_score = solveTab(nums);

        int p2_score = total_score - p1_score; // player2's score 

        bool isP1Winner = p1_score >= p2_score; // can player 1 win

        return isP1Winner;
    }
};