// Last updated: 02/05/2026, 22:34:54
class Solution {
public:
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};

    int dfs(vector<vector<int>>& grid, int i, int j,vector<vector<bool>>& vis, int m, int n){
        vis[i][j] = true;

        int fish = grid[i][j];

        for(int k = 0; k<4; k++){
            int nx = i + dx[k], ny = j + dy[k];

            if(nx >=0 && nx < m && ny >=0 && ny<n && !vis[nx][ny] && grid[nx][ny] > 0){
                fish += dfs(grid, nx, ny, vis, m, n);
            }
        }

        return fish;
    }
    int findMaxFish(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int maxFish = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){

                if(grid[i][j] > 0 && !visited[i][j]){
                    maxFish = max(maxFish, dfs(grid, i, j, visited, m, n));
                }
            }
        }

        return maxFish;
        
    }
};