// Last updated: 02/05/2026, 22:37:00
class Solution {
public:
    long long solve(int idx, vector<vector<int>>& questions, vector<long long>& dp){

        int n = questions.size();

        //base case
        if(idx >= n){
            return 0LL;
        }

        if(dp[idx] != -1) return dp[idx];

        //solving the current question
        int next_idx = idx+1 + questions[idx][1];
        long long solveQuestion = questions[idx][0] + solve(next_idx, questions, dp);

        //skipping the current question
        long long skipQuestion = 0 + solve(idx+1, questions, dp);

        return dp[idx] = max(solveQuestion, skipQuestion);

    }
    long long solveTab(vector<vector<int>>& questions){
        
        int n = questions.size();
        vector<long long> dp(n+1, 0LL);

        for(int i = n-1; i >= 0; i--){

            //solving the current question
            int next_idx = i+1 + questions[i][1];
            long long solveQuestion = questions[i][0] + ((next_idx < n) ? dp[next_idx] : 0LL);

            //skipping the current question
            long long skipQuestion = 0;
            skipQuestion = dp[i+1];

            dp[i] = max(solveQuestion, skipQuestion);
        }

        return dp[0];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        // vector<long long> dp(n, -1);
        // return solve(0, questions, dp);

        return solveTab(questions);
    }
};