// Last updated: 02/05/2026, 22:42:16
class Solution {
public:
    int solve(string& s, int idx, int prev, vector<vector<int>>& dp){
        int n = s.length();

        if(idx >= n){
            return 0;
        }

        if(dp[idx][prev] != -1) return dp[idx][prev];

        int flip = INT_MAX;
        int no_flip = INT_MAX;

        if(s[idx] == '0'){

            if(prev == 1){
                flip = 1 + solve(s, idx+1, 1, dp);
            }
            else if(prev == 0){
                flip = 1 + solve(s, idx+1, 1, dp);
                no_flip = solve(s, idx+1, 0, dp);
            }

        }else if(s[idx] == '1'){

            if(prev == 1){
                no_flip = solve(s, idx+1, 1, dp);
            }else{
                flip = 1 + solve(s, idx+1, 0, dp);
                no_flip = solve(s, idx+1, 1, dp);
            }
        }

        return dp[idx][prev] = min(flip, no_flip);
    }
    int minFlipsMonoIncr(string s) {
        int n = s.length();

        vector<vector<int>> dp(n+1, vector<int>(2, -1));

        return solve(s, 0, 0, dp);
    }
};