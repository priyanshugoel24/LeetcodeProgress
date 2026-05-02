// Last updated: 02/05/2026, 22:41:58
class Solution {
public:
    int time = 0;
    vector<pair<int,int>> directions = {{-1, 0}, {1,0}, {0,-1}, {0,1}};

    void bfs(queue<pair<pair<int,int>, int>>& q, vector<vector<int>>& visited, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(t, time);
            q.pop();

            visited[row][col] = 2;

            for(auto dir : directions){
                int nrow = row + dir.first;
                int ncol = col + dir.second;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && visited[nrow][ncol] != 2){
                    visited[nrow][ncol] = 2;
                    q.push({{nrow, ncol} , t+1});
                    grid[nrow][ncol] = 2;
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        queue<pair<pair<int,int>, int>> q;


        for(int row = 0; row<n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == 2){
                    q.push({{row, col}, 0});
                }
            }
        }

        bfs(q, visited, grid);

        for(int row = 0; row<n; row++){
            for(int col = 0; col<m; col++){
                if(grid[row][col] == 1){
                    return -1;
                }
            }
        }

        return time;
        


        
    }
};