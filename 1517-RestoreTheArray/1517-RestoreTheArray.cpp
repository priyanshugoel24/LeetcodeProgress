// Last updated: 02/05/2026, 22:39:50
class Solution {
public:
    int solve(int start, string& s, int& k, vector<int>& dp){
        int mod = 1e9 + 7;
        int n = s.length();

        //base case
        if(start >= n){
            return 1;
        }
        if(s[start] == '0'){
            return 0;
        }

        if(dp[start] != -1) return dp[start];

        long ans = 0;

        long long num = 0;

        for(int end = start; end < n; end++){

            num = (num * 10) + (s[end] - '0');

            if(num > k ) break;

            ans = (ans % mod + solve(end + 1, s, k, dp) % mod) % mod;
        }

        return dp[start] = ans;
    }
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<int> dp(n+1, -1);
        return solve(0, s, k, dp);
    }
};