// Last updated: 02/05/2026, 22:42:04
class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    void backTrack(vector<vector<int>>& grid, int count, int& ways, int nonObstacles, int i, int j, int m, int n){

        if(i < 0 || i >= m || j<0 || j>=n || grid[i][j] == -1) return;

        if(grid[i][j] == 2){
            if(count == nonObstacles) ways++;
            return;
        }

        grid[i][j] = -1;

        for(vector<int> &dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            backTrack(grid, count+1, ways, nonObstacles, new_i, new_j, m, n);
        }

        grid[i][j] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ways = 0;
        int nonObstacles = 0;

        int start_x = 0, start_y = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
              if(grid[i][j] == 0) nonObstacles++;

              if(grid[i][j] == 1){
                start_x = i;
                start_y = j;
              }  
            }
        }

        nonObstacles += 1;

        int count = 0;

        backTrack(grid, count, ways, nonObstacles, start_x, start_y, m, n);

        return ways;
    }
};