// Last updated: 02/05/2026, 22:42:21
class Solution {
public:
    pair<int, int> getCoordinates(int num, int n) {
        int row = n - 1 - (num - 1) / n;
        int col = (num - 1) % n;

        if ((n - 1 - row) % 2 == 1) {
            col = n - 1 - col;
        }

        return {row, col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();

        int diceMove = 0;
        queue<int> q;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[n - 1][0] = true;

        q.push(1);

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                int curr = q.front();
                q.pop();

                if (n * n == curr)
                    return diceMove;

                for (int i = 1; i <= 6; i++) {

                    int next = curr + i;

                    if (next > n * n)
                        break;

                    pair<int, int> coordinates = getCoordinates(next, n);

                    int row = coordinates.first;
                    int col = coordinates.second;

                    if (visited[row][col] == true)
                        continue;

                    visited[row][col] = true;

                    if (board[row][col] == -1) {
                        q.push(next);
                    } else {
                        q.push(board[row][col]);
                    }
                }
            }

            diceMove++;
        }

        return -1;
    }
};