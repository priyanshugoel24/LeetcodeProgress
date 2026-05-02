// Last updated: 02/05/2026, 22:48:15
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = m; i>=0; i--){
            for(int j = n; j>=0; j--){

                if(i == m) dp[i][j] = n-j;
                else if(j == n) dp[i][j] = m -i;
                else{

                    if(word1[i] == word2[j]){
                        dp[i][j] = dp[i+1][j+1];
                    }
                    else{

                        int insertC = 1 + dp[i][j+1];
                        int replaceC = 1 + dp[i+1][j+1];
                        int deleteC = 1 + dp[i+1][j];

                        dp[i][j] = min({insertC, replaceC, deleteC});
                    }
                }
            }
        }

        return dp[0][0];
    }
};