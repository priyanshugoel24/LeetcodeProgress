// Last updated: 02/05/2026, 22:40:12
class Solution {
public:
    int solve(vector<int>& jobDifficulty, int n, int idx, int d,
              vector<vector<int>>& dp) {

        // base case
        // if only one day is left we have to perform all jobs in that day and
        // return max difficulty
        if (d == 1) {
            int maxDifficulty = jobDifficulty[idx];

            for (int i = idx; i < n; i++) {
                maxDifficulty = max(maxDifficulty, jobDifficulty[i]);
            }

            return maxDifficulty;
        }

        // if subproblem is already solved
        if (dp[idx][d] != -1)
            return dp[idx][d];

        // split into d sections
        int maxDifficulty = jobDifficulty[idx];
        int minimumDifficultyofSchedule = INT_MAX;

        for (int i = idx; i <= n - d; i++) {

            maxDifficulty = max(maxDifficulty, jobDifficulty[i]);

            int result =
                maxDifficulty + solve(jobDifficulty, n, i + 1, d - 1, dp);

            minimumDifficultyofSchedule =
                min(minimumDifficultyofSchedule, result);
        }

        return dp[idx][d] = minimumDifficultyofSchedule;
    }

    int solveBU(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX));

        for (int i = 0; i < n; i++) {
            int maxDifficulty = 0;
            for (int k = i; k < n; k++) {
                maxDifficulty = max(maxDifficulty, jobDifficulty[k]);
            }
            dp[i][1] = maxDifficulty;
        }

        for (int j = 2; j <= d; j++) {         // days loop
            for (int i = 0; i <= n - j; i++) { // jobs loop
                int maxDifficulty = 0;

                for (int k = i; k <= n - j; k++) { // Splitting jobs
                    maxDifficulty = max(maxDifficulty, jobDifficulty[k]);
                    if (dp[k + 1][j - 1] != INT_MAX) {
                        dp[i][j] =
                            min(dp[i][j], maxDifficulty + dp[k + 1][j - 1]);
                    }
                }
            }
        }

        return dp[0][d];
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        // if the no of jobs to perform are less than no of days we cannot do 1
        // job everyday
        if (n < d) {
            return -1;
        }

        // vector<vector<int>> dp(n+1, vector<int>(d+1, -1));

        // return solve(jobDifficulty, n, 0, d, dp);

        return solveBU(jobDifficulty, d);
    }
};