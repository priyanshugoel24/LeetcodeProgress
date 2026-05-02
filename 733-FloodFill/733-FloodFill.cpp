// Last updated: 02/05/2026, 22:43:37
class Solution {
public:
    vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    void bfs(queue<pair<int,int>>& q, vector<vector<int>>& visited, vector<vector<int>>& image,int initial_colour,  int color){
        int n = image.size();
        int m = image[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            

            q.pop();

            visited[row][col] = true;

            for(auto dir : directions){
                int nrow = row + dir.first;
                int ncol = col + dir.second;
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol<m && image[nrow][ncol] == initial_colour && visited[nrow][ncol] != true){
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                    image[nrow][ncol] = color;

                }
            }
        }

        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        queue<pair<int,int>> q;

        q.push({sr, sc});
        int initial_colour = image[sr][sc];
        image[sr][sc] = color;

        bfs(q, visited, image,initial_colour,  color);
        return image;

        

        
    }
};