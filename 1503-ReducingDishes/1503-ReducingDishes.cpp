// Last updated: 02/05/2026, 22:39:57
class Solution {
public:
    int solve(int idx, int currDish, vector<int>& satisfaction, vector<vector<int>>& dp){

        int n = satisfaction.size();

        //base case
        if(idx >= n) return 0;

        if(dp[idx][currDish] != -1) return dp[idx][currDish];

        int maxLikeTimeCoeff = 0;

        //prepare the dish
        int prepare = (satisfaction[idx] * currDish) + solve(idx+1, currDish+1, satisfaction, dp);

        // leave the dish
        int not_prepare = 0 + solve(idx+1, currDish, satisfaction, dp);

        maxLikeTimeCoeff = max(prepare, not_prepare);

        return dp[idx][currDish] = maxLikeTimeCoeff;
    }
    int maxSatisfaction(vector<int>& satisfaction) {

        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, 1, satisfaction, dp);
    }
};