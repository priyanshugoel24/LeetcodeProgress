// Last updated: 02/05/2026, 22:47:20
class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis){
        int m = board.size();
        int n = board[0].size();
        vis[row][col] = 1;

       int delRow[] = {-1, 0, 1, 0};
       int delCol[] = {0, 1, 0, -1};

        for(int i = 0; i<4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >=0 && nRow <m && nCol >=0 && nCol <n && vis[nRow][nCol] == 0 && board[nRow][nCol] == 'O'){
                dfs(nRow, nCol, board, vis);

            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        //first and last row
        for(int j = 0; j<n; j++){

            //first row
            if(board[0][j] == 'O'){
                dfs(0, j, board, vis);
            }
            //last row
            if(board[m-1][j] == 'O'){
                dfs(m-1, j, board, vis);
            }
        }

        //first and last column
        for(int i = 0; i<m; i++){

            //first column
            if(board[i][0] == 'O'){
                dfs(i, 0, board, vis);
            }
            if(board[i][n-1] == 'O'){
                dfs(i, n-1, board, vis);
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(vis[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

       
        
    }
};