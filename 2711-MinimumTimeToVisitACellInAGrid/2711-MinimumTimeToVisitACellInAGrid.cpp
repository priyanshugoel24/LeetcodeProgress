// Last updated: 02/05/2026, 22:35:04
class Solution {
public:
    typedef tuple<int, int, int> t;
    int minimumTime(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        priority_queue<t, vector<t>, greater<t>> pq; // {time, x, y}
        pq.push({0, 0, 0});

        vector<vector<bool>> visited(m, vector<bool>(n, false));


        while(!pq.empty()){

            auto [time, x, y] = pq.top();
            pq.pop();

            if(x == m -1 && y == n - 1){
                return time;
            }

            if(visited[x][y]) continue;
            visited[x][y] = true;

            for(auto& dir : directions){

                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if(new_x < 0 || new_x >=m || new_y < 0 || new_y >= n || visited[new_x][new_y]) continue;

                int wait = (grid[new_x][new_y] - time) % 2 == 0;
                int new_time = max(grid[new_x][new_y] + wait, time + 1);

                pq.push({new_time, new_x, new_y});
            }
        }

        return -1;
    }
};