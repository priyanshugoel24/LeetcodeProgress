// Last updated: 02/05/2026, 22:48:14
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();

        bool firstRowImpacted = false;
        bool firstColImpacted = false;

        // check whether first row is impacted by any 0 present in the first row
        for(int col = 0; col < n; col++){

            if(matrix[0][col] == 0){
                firstRowImpacted = true;
            }
        }

        // check whether first col is impacted by any 0 present in the first col
        for(int row = 0; row < m; row++){

            if(matrix[row][0] == 0){
                firstColImpacted = true;
            }
        }

        // set markers in the first row and first col which would impact the whole row and col
        for(int row = 1; row < m; row++){

            for(int col = 1; col < n; col++){
                
                if(matrix[row][col] == 0){
                    
                    // mark the row
                    matrix[row][0] = 0;
                    //mark the col
                    matrix[0][col] = 0;
                }
            }
        }


        // traverse the remaining matrix to check impacted rows and cols and set them to zero
        for(int row = 1; row < m; row++){

            for(int col = 1; col < n; col++){

                // check the row marker
                if(matrix[row][0] == 0){
                    matrix[row][col] = 0;
                }

                // check the col marker
                if(matrix[0][col] == 0){
                    matrix[row][col] = 0;
                }
            }
        }

        // mark the first rows and first cols if they are impacted
        if(firstRowImpacted){

            for(int col = 0; col < n; col++){
                matrix[0][col] = 0;
            }
        }

        if(firstColImpacted){

            for(int row = 0; row < m; row++){
                matrix[row][0] = 0;
            }
        }
    }
};