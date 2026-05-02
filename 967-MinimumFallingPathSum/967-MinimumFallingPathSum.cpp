// Last updated: 02/05/2026, 22:42:14
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prev(m, 0);
        vector<int> curr(m, 0);

        for(int j = 0; j<m; j++) prev[j] = matrix[0][j];

        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
            int up = matrix[i][j] + prev[j];
            int leftD = matrix[i][j];
            if(j-1 >= 0) leftD += prev[j-1];
            else leftD = 1e9;
            int rightD = matrix[i][j];
            if(j+1 < m) rightD += prev[j+1];
            else rightD = 1e9;

            curr[j] = min(up, min(leftD, rightD));

            }
            prev = curr;
        }

        int ans = 1e9;
        for(int j = 0; j<m; j++){
            ans = min(ans, prev[j]);
        }

        return ans;

        
    }
};