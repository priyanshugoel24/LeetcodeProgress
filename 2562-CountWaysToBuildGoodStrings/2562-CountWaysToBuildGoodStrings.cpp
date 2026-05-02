// Last updated: 02/05/2026, 22:35:41
class Solution {
public:
    int solve(int len, int low, int high, int zero, int one, vector<int>& dp) {
        int mod = 1e9 + 7;
        // base case
        if (len > high) {
            return 0;
        }

        // if the subproblem is already solved
        if (dp[len] != -1) {
            return dp[len];
        }

        bool oneAdd = false;
        // check if len is in range so add 1
        if (len >= low && len <= high) {
            oneAdd = true;
        }

        // option1 : add 0 zero times
        int add_zero = solve(len + zero, low, high, zero, one, dp) % mod;

        // option2 : add 1 one times
        int add_one = solve(len + one, low, high, zero, one, dp) % mod;

        // return total possible good strings
        return dp[len] = ((int)oneAdd + add_zero + add_one) % mod;
    }

    int solveTab(int low, int high, int zero, int one) {
        int mod = 1e9 + 7;
        vector<int> dp(high + 1, 0);
        dp[0] = 1; // Base case: 1 way to form length 0 (empty string)

        for (int len = 1; len <= high; len++) {

            if (len - zero >= 0) {
                dp[len] = (dp[len] + dp[len - zero]) % mod;
            }

            if (len - one >= 0) {
                dp[len] = (dp[len] + dp[len - one]) % mod;
            }
        }

        int ans = 0;
        for (int len = low; len <= high; len++) {
            ans = (ans + dp[len]) % mod;
        }

        return ans;
    }

    int countGoodStrings(int low, int high, int zero, int one) {

        // vector<int> dp(high+1, -1);
        // return solve(0, low, high, zero, one, dp);

        return solveTab(low, high, zero, one);
    }
};