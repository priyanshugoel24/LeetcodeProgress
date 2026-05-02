// Last updated: 02/05/2026, 22:45:25
class Solution {
public:
    bool isSafe(vector<vector<int>>& matrix, int i, int j){

        int m = matrix.size(), n = matrix[0].size();

        if(i >= 0 && i < m && j >= 0 && j < n){
            return true;
        }

        return false;
    }
    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){

        if(dp[i][j] != -1) return dp[i][j];

        int pathLength = 1;

        vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

        for(auto dir : directions){

            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(isSafe(matrix, new_i, new_j) && matrix[new_i][new_j] > matrix[i][j]){

                pathLength = max(pathLength, 1 + solve(matrix, new_i, new_j, dp));
            }
        }

        return dp[i][j] = pathLength;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int longestPath = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                longestPath = max(longestPath, solve(matrix, i, j, dp));
            }
        }

        return longestPath;
    }
};