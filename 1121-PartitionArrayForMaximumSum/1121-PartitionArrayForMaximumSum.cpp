// Last updated: 02/05/2026, 22:41:43
class Solution {
public:
    int f(int ind, int n, vector<int>& arr, int k, vector<int>& dp){
        if(ind == n) return 0;
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        if(dp[ind] != -1) return dp[ind];

        for(int j = ind; j<min(n, ind+k); j++){
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len* maxi +f(j+1, n, arr, k, dp);
            maxAns = max(maxAns, sum);

        }
        return dp[ind] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        for(int ind = n-1; ind>=0; ind--){
            int len = 0;
            int maxi = INT_MIN;
            int maxAns = INT_MIN;

            for(int j = ind; j<min(n, ind+k); j++){
                len++;
                maxi = max(maxi, arr[j]);
                int sum = len* maxi +f(j+1, n, arr, k, dp);
                maxAns = max(maxAns, sum);

            }
            dp[ind] = maxAns;

        }
        return dp[0];
        
    }
};