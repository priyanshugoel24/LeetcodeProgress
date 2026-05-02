// Last updated: 02/05/2026, 22:39:39
class Solution {
public:
    int mod = 1e9 + 7;
    
    int solve(int i, int j, int k, vector<vector<int>>& apples, vector<string>& pizza, vector<vector<vector<int>>>& dp) {
        int m = pizza.size(), n = pizza[0].length();

        // Base cases
        if (apples[i][j] < k) return 0; // Not enough apples left for k pieces
        if (k == 1) return 1; // If only one piece is left, it's a valid way

        if (dp[i][j][k] != -1) return dp[i][j][k];

        int ans = 0;

        // Horizontal cuts
        for (int h = i + 1; h < m; h++) {
            if (apples[i][j] - apples[h][j] > 0) { // Ensure top part has at least 1 apple
                ans = (ans + solve(h, j, k - 1, apples, pizza, dp)) % mod;
            }
        }

        // Vertical cuts
        for (int v = j + 1; v < n; v++) {
            if (apples[i][j] - apples[i][v] > 0) { // Ensure left part has at least 1 apple
                ans = (ans + solve(i, v, k - 1, apples, pizza, dp)) % mod;
            }
        }

        return dp[i][j][k] = ans;
    }

    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(), n = pizza[0].length();

        // Apples[i][j] = number of apples in sub-grid from (i,j) to (m-1,n-1)
        vector<vector<int>> apples(m + 1, vector<int>(n + 1, 0));

        // Compute apples suffix sum
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                apples[i][j] = (pizza[i][j] == 'A') ? 1 : 0;
                apples[i][j] += apples[i + 1][j] + apples[i][j + 1] - apples[i + 1][j + 1];
            }
        }

        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(k+1, -1)));

        return solve(0, 0, k, apples, pizza, dp);
    }
};
