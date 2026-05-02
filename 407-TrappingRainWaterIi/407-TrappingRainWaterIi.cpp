// Last updated: 02/05/2026, 22:45:01
class Solution {
public:
    typedef pair<int, pair<int,int>> PP;
    vector<vector<int>> directions = {{0,-1}, {0,1}, {-1, 0}, {1, 0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        int m = heightMap.size(), n = heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<>> boundaryCells; // minHeap to get smallest boundary wall

        vector<vector<bool>> visited(m, vector<bool>(n, false)); // visited vector
        

        //for leftmost and rightmost column
        for(int row = 0; row <m; row++){
            for(int col : {0, n-1}){
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        // for topmost and bottom row
        for(int col = 0; col < n; col++){
            for(int row : {0, m-1}){
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        int water = 0;

        while(!boundaryCells.empty()){
            PP top = boundaryCells.top();
            boundaryCells.pop();

            int height = top.first;
            int row = top.second.first;
            int col = top.second.second;

            //find neighbours
            for(vector<int>& dir : directions){
                int nRow = row + dir[0];
                int nCol = col + dir[1];

                if(nRow >= 0 && nRow < m && nCol >=0 && nCol < n && !visited[nRow][nCol]){
                    water += max(height - heightMap[nRow][nCol], 0);

                    boundaryCells.push({max(height, heightMap[nRow][nCol]), {nRow, nCol}});
                    

                    visited[nRow][nCol] = true;
                }
            }


        }


        return water;
    }
};