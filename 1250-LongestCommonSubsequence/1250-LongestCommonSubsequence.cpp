// Last updated: 02/05/2026, 22:41:16
class Solution {
public:
    int solve(string text1, string text2, int i, int j, vector<vector<int>>& dp){
        //base case
        if(i >= text1.size() || j >= text2.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;

        if(text1[i] == text2[j]){
            ans = 1 + solve(text1, text2, i+1, j+1, dp);
        }
        else{
            ans = max( solve(text1, text2, i+1, j, dp), solve(text1, text2, i, j+1, dp));
        }

        return dp[i][j] = ans;
    }

    int solveTab(string a, string b){
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){

                int ans = 0;

                if(a[i] == b[j]){
                    ans = 1 + dp[i+1][j+1];
                }
                else{
                    ans = max( dp[i+1][j], dp[i][j+1]);
                }

                dp[i][j] = ans;


            }
        }

        return dp[0][0];
        
    }

    int solveopt(string a, string b){
        int n = a.size();
        int m = b.size();

        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);

        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){

                int ans = 0;

                if(a[i] == b[j]){
                    ans = 1 + next[j+1];
                }
                else{
                    ans = max( next[j], curr[j+1]);
                }

                curr[j] = ans;


            }

            next = curr;
        }

        return next[0];


    }
    

    int longestCommonSubsequence(string text1, string text2) {
        /*int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(text1, text2, 0, 0, dp);*/

        return solveopt(text1, text2);
        
    }
};