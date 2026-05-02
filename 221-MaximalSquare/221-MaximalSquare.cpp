// Last updated: 02/05/2026, 22:46:17

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        int maxi = 0;
        

        for(int i=n-1;i>=0;i--){
            for(int j=m-1; j>=0 ;j--){
                    int right     = dp[i][j+1];
                    int down      = dp[i+1][j];
                    int diagnoal  = dp[i+1][j+1];
                    int curr =0;
                    if(matrix[i][j]=='1'){
                        curr = 1 + min(right , min(down, diagnoal));
                        dp[i][j] = curr;
                        maxi = max(maxi ,curr);
                         curr;
                    }else{

                         dp[i][j] = 0;
                    }
                        }
            }

         return maxi * maxi;
    }
};