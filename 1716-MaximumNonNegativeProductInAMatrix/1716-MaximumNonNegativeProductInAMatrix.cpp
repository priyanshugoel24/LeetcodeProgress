// Last updated: 02/05/2026, 22:39:02
class Solution {
public:
    typedef long long ll;
    int mod = 1e9 + 7;

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<pair<ll, ll>>> dp(m, vector<pair<ll, ll>>(n));

        dp[0][0] = {grid[0][0], grid[0][0]};

        // Fill the first row
        for (int j = 1; j < n; j++) {
            dp[0][j] = {
                dp[0][j - 1].first * grid[0][j],
                dp[0][j - 1].second * grid[0][j]
            };
        }

        // Fill the first column
        for (int i = 1; i < m; i++) {
            dp[i][0] = {
                dp[i - 1][0].first * grid[i][0],
                dp[i - 1][0].second * grid[i][0]
            };
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                ll upMax = dp[i - 1][j].first;
                ll upMin = dp[i - 1][j].second;
                ll leftMax = dp[i][j - 1].first;
                ll leftMin = dp[i][j - 1].second;

                ll val = grid[i][j];

                // Calculate new min and max values
                ll newMax = max({upMax * val, upMin * val, leftMax * val, leftMin * val});
                ll newMin = min({upMax * val, upMin * val, leftMax * val, leftMin * val});

                dp[i][j] = {newMax, newMin};
            }
        }

        ll maxProduct = dp[m-1][n-1].first;

        return maxProduct < 0 ? -1 : (maxProduct % mod);
    }
};