// Last updated: 02/05/2026, 22:32:59
class Solution {
public:
    long long mod = 1e9 + 7;
    vector<long long> fact, fact_inv;
    void precomputeFactorials(int maxN) {
        fact.resize(maxN + 1, 1);
        fact_inv.resize(maxN + 1, 1);
        for (int i = 2; i <= maxN; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        fact_inv[maxN] = mod_inv(fact[maxN]);
        for (int i = maxN - 1; i > 0; i--) {
            fact_inv[i] = (fact_inv[i + 1] * (i + 1)) % mod;
        }
        fact_inv[0] = 1;
    }
    long long mod_inv(long long x) {
        long long res = 1, power = mod - 2;
        while (power) {
            if (power % 2) res = res * x % mod;
            x = x * x % mod;
            power /= 2;
        }
        return res;
    }

    long long ncr(long long n, long long r) {
        if (r > n || r < 0) return 0;
        return (fact[n] * fact_inv[r] % mod * fact_inv[n - r] % mod) % mod;
    }
    long long dp[10][801][81];

    long long solve(int digit, int diff, int ol, vector<int>& v, int& n, vector<int>& prefix) {
        if (diff > 400 || diff < -400) return 0;
        long long sum = digit > 0 ? prefix[digit - 1] : 0;
        long long el = n - sum - ol;

        if (ol < 0 || el < 0) return 0;
        if (digit >= 10) return diff == 0;
        if (dp[digit][diff + 400][ol] != -1) return dp[digit][diff + 400][ol];

        long long ans = 0;
        for (int i = 0; i <= v[digit]; i++) {
            long long new_diff = diff + (i * digit) - ((v[digit] - i) * digit);
            long long combo = (ncr(ol, i) * ncr(el, v[digit] - i)) % mod;
            ans = (ans + solve(digit + 1, new_diff, ol - i, v, n, prefix) * combo % mod) % mod;
        }

        return dp[digit][diff + 400][ol] = ans;
    }

    int countBalancedPermutations(string s) {
        vector<int> v(10, 0);
        for (char c : s) v[c - '0']++;

        vector<int> prefix(10, 0);
        int sum = 0;
        for (int i = 0; i < prefix.size(); i++) {
            sum += v[i];
            prefix[i] = sum;
        }

        memset(dp, -1, sizeof(dp));
        int n = s.size();
        int total_odd = n / 2;
        int total_even = n - total_odd;

        precomputeFactorials(n);

        return solve(0, 0, total_even, v, n, prefix);
    }
};
