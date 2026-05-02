// Last updated: 02/05/2026, 22:39:49
class Solution {
public:
    int solve(vector<int>& stones, int idx, vector<int>& dp){
        int n = stones.size();

        //base case
        if(idx >= n){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        int result = stones[idx] - solve(stones, idx+1, dp);

        if(idx +1 < n)
            result = max(result, stones[idx] + stones[idx+1] - solve(stones, idx+2, dp));

        if(idx + 2 < n)
            result = max(result, stones[idx] + stones[idx+1] + stones[idx+2] - solve(stones, idx + 3, dp));

        return dp[idx] = result;
    }
    int solveTab(vector<int>& stones){

        int n = stones.size();
        vector<int> dp(n+1, 0);

        for(int idx = n - 1 ; idx >= 0; idx--){

            int result = stones[idx] - dp[idx+1];

            if(idx + 2 <= n)
                result = max(result, stones[idx] + stones[idx+1] - dp[idx+ 2]);

            if(idx + 3 <= n)
                result = max(result, stones[idx] + stones[idx+1] + stones[idx+2] - dp[idx+3]);

            dp[idx] = result;
        }

        return dp[0];
    }

    int solveSO(vector<int>& stones){

        int n = stones.size();

        //3 possibilites for every index
        int a = 0;
        int b = 0;
        int c = 0;

        for(int idx = n-1; idx >= 0; idx--){

            int result = INT_MIN;

            result = max(result, stones[idx] - a);

            if(idx + 2 <= n)
                result = max(result, stones[idx] + stones[idx + 1] - b);

            if(idx + 3 <= n)
                result = max(result, stones[idx] + stones[idx+1] + stones[idx + 2] - c);

            c = b;
            b = a;
            a = result;
        }

        return a;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        
        int n = stoneValue.size();
        vector<int> dp(n+1, -1);

        // int diff = solve(stoneValue, 0, dp);

        // int diff = solveTab(stoneValue);

        int diff = solveSO(stoneValue);

        if(diff < 0){
            return "Bob";
        }else if(diff > 0){
            return "Alice";
        }

        return "Tie";

    }
};