// Last updated: 02/05/2026, 22:44:16
class Solution {
public:
    int solve(string s, string t){

    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int j = 0; j<=m; j++) dp[0][j] = 0;
    for(int i = 0; i<=n; i++) dp[i][0] = 0;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
   }   
    int minDistance(string word1, string word2) {

        // no of deletions -> n - lcs(word1, word2);
        // no of insertions -> m - lcs(word1, word2)
        // total = no.of deletions + no.of insertions

        return (word1.size() + word2.size()) - (2 * solve(word1, word2));

        
    }
};