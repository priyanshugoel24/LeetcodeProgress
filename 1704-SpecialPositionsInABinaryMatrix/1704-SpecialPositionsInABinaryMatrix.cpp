// Last updated: 02/05/2026, 22:39:07
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();

        vector<int> onesRowCount(m, 0), onesColCount(n, 0);

        for(int row = 0; row < m; row++){

            for(int col = 0; col < n; col++){

                if(mat[row][col] == 1){

                    onesRowCount[row]++, onesColCount[col]++;
                }
            }
        }

        int specialOnes = 0;

        for(int row = 0; row < m; row++){

            for(int col = 0; col < n; col++){

                if(mat[row][col] == 1){

                    if(onesRowCount[row] == 1 && onesColCount[col] == 1) specialOnes++;
                }
            }
        }

        return specialOnes;
    }
};