// Last updated: 02/05/2026, 22:47:17
class Solution {
public:
    int minCut(string s) {
        int n = s.length();

        vector<vector<bool>> t(n, vector<bool>(n, false));
        //t[i][j] = true/false means s[i..j] substring is palindrome or not

        for(int i = 0; i<n; i++){
            t[i][i] = true; // 1 length string is always palindrome
        }

        for(int L = 2; L <= n; L++){
            for(int i = 0; i < n - L + 1; i++){

                int j = i + L - 1;

                if(L == 2 && s[i] == s[j]){
                    t[i][j] = true;
                }else{

                    t[i][j] = (s[i] == s[j] && t[i+1][j-1]);
                }

            }
        }

        vector<int> dp(n);
        //dp[i] = min cuts required to cut a string s[0---i] into palindromes

        for(int i = 0; i < n; i++){
           if(t[0][i] == true){ // s[0....i] is a palindrome
                dp[i] = 0; // no cuts required
            }else{
                dp[i] = INT_MAX;

                for(int k = 0; k < i; k++){
                    if(t[k+1][i] == true && 1 + dp[k] < dp[i]){
                        dp[i] = 1 + dp[k];
                    }
                }
            }
        }

        return dp[n-1];

    }
};