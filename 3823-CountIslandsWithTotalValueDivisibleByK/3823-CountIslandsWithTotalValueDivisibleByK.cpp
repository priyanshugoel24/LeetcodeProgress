// Last updated: 02/05/2026, 22:32:26
class Solution {
public:
    long long dfs(int row, int col, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Base Case: Stop if out of bounds or on water/a visited cell.
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0) {
            return 0;
        }

        // Store the value of the current cell.
        long long current_value = grid[row][col];

        // Mark the current cell as visited by setting it to 0.
        grid[row][col] = 0;

        // Recursively visit all 4 neighbors and add their values to the total.
        long long island_total_value = current_value;
        island_total_value += dfs(row + 1, col, grid); // Down
        island_total_value += dfs(row - 1, col, grid); // Up
        island_total_value += dfs(row, col + 1, grid); // Right
        island_total_value += dfs(row, col - 1, grid); // Left

        return island_total_value;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();
        int valid_islands = 0;

        // Iterate through each cell in the grid.
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                // If we find a non-zero cell, it means we've found a new, unvisited island.
                if (grid[row][col] != 0) {
                    // This DFS call will find the total value and also sink the entire island.
                    long long island_value = dfs(row, col, grid);

                    if (island_value % k == 0) {
                        valid_islands++;
                    }
                }
            }
        }

        return valid_islands;
    }
};