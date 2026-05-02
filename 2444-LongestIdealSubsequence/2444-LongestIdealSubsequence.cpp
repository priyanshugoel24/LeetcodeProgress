// Last updated: 02/05/2026, 22:36:15
class Solution {
public:
    int solve(int idx, string&s, int n, char prevChar, int k, vector<vector<int>>& dp){

        // base case : processed the whole string
        if(idx == n){

           return 0;
        }

        //indexing for previous character taken
        int key = (prevChar == '/') ? 0 : (prevChar - 'a' + 1);

        //if the subproblem is already solved
        if(dp[idx][key] != -1){
            return dp[idx][key];
        }

        //option 1 : take the current character if possible
        int take = 0;
        if(prevChar == '/' || (abs(s[idx] - prevChar) <= k)){
            take = 1 + solve(idx + 1 , s, n, s[idx], k, dp);
        }

        //option 2 : skip the current character
        int skip = solve(idx + 1, s, n, prevChar, k, dp);

        // memoize the result
        return dp[idx][key] = max(skip, take);
    }
    int longestIdealString(string s, int k) {
        
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(27, -1));

        return solve(0, s, n, '/', k, dp);
    }
};