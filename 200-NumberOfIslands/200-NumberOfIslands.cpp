// Last updated: 02/05/2026, 22:46:36
class Solution {
public:
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    int dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& vis, int m, int n){
        vis[i][j] = true;

        for(int k = 0; k<4; k++){
            int nx = i + dx[k], ny = j + dy[k];

            if(nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && grid[i][j] == '1'){
                dfs(grid, nx, ny, vis, m, n);
            }
        }

        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int islands = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){

                if(grid[i][j] == '1' && !visited[i][j]){
                    islands += dfs(grid, i, j, visited, m, n);
                }
            }
        }

        return islands;
        
    }
};