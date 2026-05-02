// Last updated: 02/05/2026, 22:49:19
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        vector<vector<bool>> dp(n, vector<bool>(n));

        int maxlen = 0;
        int idx = 0;

        for(int i = 0; i<n; i++){
            dp[i][i] = true;
            maxlen = 1;
        }

        for(int L = 2; L <= n; L++){
            for(int i = 0; i< n-L+1; i++){
                int j = i + L -1;

                if(s[i] == s[j] && L == 2){
                    dp[i][j] = true;
                    maxlen = 2;
                    idx = i;
                }else if(s[i] == s[j] && dp[i+1][j-1] == true){
                    dp[i][j] = true;
                    if(j-i+1 > maxlen){
                        maxlen = j - i + 1;
                        idx = i;
                    }
                }else{
                    dp[i][j] = false;
                }
            }
        }

        return s.substr(idx, maxlen);
    }
};