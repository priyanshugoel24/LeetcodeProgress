// Last updated: 02/05/2026, 22:44:24
class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void bfs(queue<pair<pair<int, int>, int>>& q, vector<vector<int>>& visited,
             vector<vector<int>>& distance, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            visited[row][col] = 1;
            distance[row][col] = dist;

            for (auto dir : directions) {
                int nrow = row + dir.first;
                int ncol = col + dir.second;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    mat[nrow][ncol] == 1 && !visited[nrow][ncol]) {
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, dist + 1});
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (mat[row][col] == 0) {
                    q.push({{row, col}, 0});
                    visited[row][col] = 1;
                }
            }
        }

        bfs(q, visited, distance, mat);

        return distance;
    }
};