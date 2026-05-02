// Last updated: 02/05/2026, 22:34:41
class Solution {
public:
    static long long ipow_bounded(int a, int b, int n) {
        long long res = 1, base = a;
        while (b) {
            if (b & 1) {
                res *= base;
                if (res > n) return (long long)n + 1;
            }
            b >>= 1;
            if (b) {
                base *= base;
                if (base > n) return (long long)n + 1;
            }
        }
        return res;
    }

    int numberOfWays(int n, int x) {
        // find maxDigit s.t. digit^x <= n
        int maxDigit = 0;
        for (int d = 1; ; ++d) {
            if (ipow_bounded(d, x, n) > n) break;
            maxDigit = d;
        }

        const int MOD = 1'000'000'007;

        // dp[d][s] = ways using bases d..maxDigit to reach sum s
        vector<vector<int>> dp(maxDigit + 2, vector<int>(n + 1, 0));
        for (int d = 0; d <= maxDigit + 1; ++d) dp[d][n] = 1;  // reaching sum n = 1 way

        for (int currDigit = maxDigit; currDigit >= 1; --currDigit) {
            int p = (int)ipow_bounded(currDigit, x, n); // currDigit^x (bounded)
            for (int currSum = n; currSum >= 0; --currSum) {
                long long ways = dp[currDigit + 1][currSum]; // skip currDigit
                int newSum = currSum + p;
                if (p <= n && newSum <= n) {
                    ways += dp[currDigit + 1][newSum];       // take currDigit
                }
                dp[currDigit][currSum] = (int)(ways % MOD);
            }
        }

        return dp[1][0]; // start with digit 1 and sum 0
    }
};