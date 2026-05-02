// Last updated: 02/05/2026, 22:37:34
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        int operations = 0;
        vector<int> v;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                v.push_back(grid[i][j]);
            }
        }

        //sort vector to find median
        sort(v.begin(), v.end());
        int len = v.size();

        int target = v[len/2];

        for(int num : v){
            if(num%x != target%x){
                return -1;
            }

            operations += abs(target-num)/x;
        }

        return operations;

    }
};