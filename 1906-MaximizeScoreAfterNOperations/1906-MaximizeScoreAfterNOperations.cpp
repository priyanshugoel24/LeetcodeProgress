// Last updated: 02/05/2026, 22:38:27
class Solution {
public:
    int solve(vector<int>& nums, vector<bool>& vis, int operationNo, unordered_map<vector<bool>, int>& dp){

        //if the subproblem is already solved
        if(dp.find(vis) != dp.end()){
            return dp[vis];
        }

        int n = nums.size();

        int maxScore = 0; // maxScore possible 

        for(int i = 0; i <= n - 2; i++){
            
            if(vis[i]) continue; // if the ith index is already used

            for(int j = i + 1; j < n; j++){

                if(vis[j]) continue; // if the jth index is already used

                //mark both index true and calculate score
                vis[i] = true;
                vis[j] = true;

                //score calculation
                int score = operationNo * (__gcd(nums[i], nums[j]));
                int remainingScore = solve(nums, vis, operationNo + 1, dp);

                //update maxScore
                maxScore = max(maxScore, score + remainingScore);

                //backtrack
                vis[i] = false;
                vis[j] = false;
            }
        }

        return dp[vis] = maxScore;
    }
    int maxScore(vector<int>& nums) {

        int n = nums.size();
        
        int operation = 1; // starting operations from 1 till n/2
        vector<bool> vis(n, false); // to mark whether a num has been used already
        unordered_map<vector<bool>, int> dp; // dp using unordered map

        return solve(nums, vis, operation, dp);

        
    }
};