// Last updated: 02/05/2026, 22:43:45
class Solution {
public:
    double solve(int n, int k, int row, int col, vector<vector<vector<double>>>& dp) {
        // base case: out of board
        if (row < 0 || row >= n || col < 0 || col >= n) {
            return 0;
        }

        // all moves done
        if (k == 0) {
            return 1;
        }

        // if subproblem is already solved
        if (dp[row][col][k] != -1) {
            return dp[row][col][k];
        }

        double probability = 0; // probability that knight stays on board

        vector<vector<int>> directions = {
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
        };

        for (auto &dir : directions) {
            int new_x = row + dir[0];
            int new_y = col + dir[1];
            probability += 0.125 * solve(n, k - 1, new_x, new_y, dp); // 1/8th possibility of every move
        }

        return dp[row][col][k] = probability;
    }

    double knightProbability(int n, int k, int row, int column) {

        //dp[row][col][moveNo]
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        return solve(n, k, row, column, dp);
    }
};
