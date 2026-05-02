// Last updated: 02/05/2026, 22:36:36
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        deque<tuple<int, int>> dq;
        dq.push_front({0, 0});

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (auto& dir : directions) {
                int new_x = x + dir[0], new_y = y + dir[1];

                if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n) continue;

                int wt = grid[new_x][new_y];

                if (dist[new_x][new_y] > dist[x][y] + wt) {
                    dist[new_x][new_y] = dist[x][y] + wt;

                    if (wt == 1)
                        dq.push_back({new_x, new_y});
                    else
                        dq.push_front({new_x, new_y});
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};
