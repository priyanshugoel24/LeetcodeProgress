// Last updated: 02/05/2026, 22:47:30
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();

        vector<int> curr(n, 0);
        vector<int> next(n, 0);

        for(int j = 0; j<n; j++){
            next[j] = triangle[m-1][j];
        }

        for(int i = m-2; i>=0; i--){
            for(int j = i; j>=0; j--){
                int down = triangle[i][j] + next[j];
                int diagonal = triangle[i][j] + next[j+1];

                curr[j] = min(down, diagonal);

            }
            next = curr;
        }

        return next[0];   
        
    }
};