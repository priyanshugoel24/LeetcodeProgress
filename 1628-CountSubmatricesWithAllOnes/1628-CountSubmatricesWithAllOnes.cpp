// Last updated: 02/05/2026, 22:39:23
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();

        int result = 0;

        for(int startRow = 0; startRow < m; startRow++){

            vector<int> vec(n, 1);
            for(int endRow = startRow; endRow < m; endRow++){

                for(int col = 0; col < n; col++){
                    
                    vec[col] = vec[col] & mat[endRow][col];

                }

                result += OnedArrayCount(vec);
            }
        }

        return result;
    }

    int OnedArrayCount(vector<int>& vec){

        int cons = 0;
        int subCount = 0;

        for(int &val : vec){

            if(val == 0) cons = 0;
            else cons++;

            subCount += cons;
        }

        return subCount;
    }
};