// Last updated: 02/05/2026, 22:40:34
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> rows(grid.size());
        vector<int> cols(grid[0].size());

        //calculate row and column sums
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }

        int ans = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) ans++;
            }
        }

        return ans;
        
    }
};