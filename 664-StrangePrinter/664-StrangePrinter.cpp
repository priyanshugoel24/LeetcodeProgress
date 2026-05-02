// Last updated: 02/05/2026, 22:43:53
class Solution {
public:
    int solve(int l, int r, string &s, vector<vector<int>>& dp){

        if(l == r){
            return 1;
        }
        if(l > r){
            return 0;
        }

        if(dp[l][r] != -1){
            return dp[l][r];
        }

        int i = l + 1;

        while(i <= r && s[i] == s[l]){
            i++;
        }

        if(i == r + 1){
            return 1;
        }

        int basic = 1 + solve(i, r, s, dp);

        int optimum = INT_MAX;

        for(int j = i ; j <= r; j++){

            if(s[j] == s[l]){

                int ans = solve(i, j-1, s, dp) + solve(j, r, s, dp);

                optimum = min(optimum, ans);
            }
        }

        return dp[l][r] = min(basic, optimum);

    }
    int strangePrinter(string s) {
        
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n , -1));

        return solve(0, n - 1, s, dp);

    }
};