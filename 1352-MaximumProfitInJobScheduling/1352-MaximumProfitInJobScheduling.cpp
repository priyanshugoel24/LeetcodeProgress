// Last updated: 02/05/2026, 22:40:47
class Solution {
public:
    int solve(int idx, vector<int>& startTime, vector<int>& endTime, vector<int>& profit, vector<int>& dp) {
        int n = profit.size();
        if (idx >= n) return 0; // Base case

        if(dp[idx] != -1) return dp[idx];

        // Find the next job that starts after the current job ends
        int nextJob = idx + 1;
        while (nextJob < n && startTime[nextJob] < endTime[idx]) {
            nextJob++;
        }

        // Take the current job and jump to the next available one
        int take = profit[idx] + solve(nextJob, startTime, endTime, profit, dp);

        // Skip the current job
        int notTake = solve(idx + 1, startTime, endTime, profit, dp);

        return dp[idx] = max(take, notTake);
    }

    int solveTab(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
        int n = startTime.size();

        vector<int> dp(n+1, 0);

        for(int idx = n-1; idx>= 0; idx--){

            int nextJob = lower_bound(startTime.begin(), startTime.end(), endTime[idx]) - startTime.begin();
            // Take the current job and jump to the next available one
            int take = profit[idx] + dp[nextJob];

            // Skip the current job
            int notTake = dp[idx+1];

            dp[idx] = max(take, notTake);


        }

        return dp[0];
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        // Sort jobs by start time
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return startTime[a] < startTime[b];
        });

        vector<int> sortedStart(n), sortedEnd(n), sortedProfit(n);
        for (int i = 0; i < n; i++) {
            sortedStart[i] = startTime[indices[i]];
            sortedEnd[i] = endTime[indices[i]];
            sortedProfit[i] = profit[indices[i]];
        }
        // vector<int> dp(n, -1);

        // return solve(0, sortedStart, sortedEnd, sortedProfit, dp);

        return solveTab(sortedStart, sortedEnd, sortedProfit);
    }
};