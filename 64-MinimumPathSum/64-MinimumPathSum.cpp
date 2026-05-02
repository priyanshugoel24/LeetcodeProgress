// Last updated: 02/05/2026, 22:48:20
class Solution {
public:
    int solve(vector<vector<int>>& grid, int row, int col, int m, int n,
              vector<vector<int>>& dp) {

        // base case
        if (row == m - 1 && col == n - 1) {
            return grid[row][col];
        }

        if (row >= m || col >= n) {
            return INT_MAX;
        }

        if (dp[row][col] != -1)
            return dp[row][col];

        int pathSum = grid[row][col];

        // right movement
        int right = solve(grid, row, col + 1, m, n, dp);

        // down movement
        int down = solve(grid, row + 1, col, m, n, dp);

        return dp[row][col] = pathSum + min(right, down);
    }

    int solveTab(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        dp[m - 1][n - 1] = grid[m - 1][n - 1];

        for (int j = n - 2; j >= 0; j--) {
            dp[m - 1][j] = grid[m - 1][j] + dp[m - 1][j + 1];
        }

        // Fill the last column (only downward moves)
        for (int i = m - 2; i >= 0; i--) {
            dp[i][n - 1] = grid[i][n - 1] + dp[i + 1][n - 1];
        }

        // Fill the rest of the dp table
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
            }

           
        }

        return dp[0][0];
    }

        int minPathSum(vector<vector<int>> & grid) {

            int m = grid.size(), n = grid[0].size();
            // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
            // return solve(grid, 0, 0, m, n, dp);

            return solveTab(grid);
        }
    };