// Last updated: 02/05/2026, 22:42:58
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        
        // base case : if Alice never draws or max possible score from K i.e k + maxPts - 1 is less than equal to n, the probability is sure event
        if(k == 0 || k + maxPts - 1 <= n) return 1.0;

        vector<double> dp(n + maxPts + 1, 0.0);
        // dp[currSum] -> probability of ending with less than equal to n points giveen curr sum
        // n + maxPts, as transition can look up ahead to maxpts even when we reach n 

        // base case : if k <= currSum <= n, then it is a sure event
        for(int sum = k; sum <= n; sum++){
            dp[sum] = 1.0;
        }

        // Maintain a sliding window of the next maxPts dp values
        // window = dp[sum+1] + dp[sum+2] + ... + dp[sum+maxPts]
        // Start with sum = k-1, so we need dp[k]..dp[k+maxPts-1].
        double window = 0.0;
        for (int sum = k; sum < k + maxPts; sum++) window += dp[sum];

        // Fill dp backwards for sum = k-1 down to 0 using:
        // dp[sum] = window / maxPts
        for (int sum = k - 1; sum >= 0; sum--) {
            dp[sum] = window / maxPts;

            // Slide the window one step left:
            // new window becomes dp[sum] + dp[sum+1] + ... + dp[sum+maxPts-1]
            window += dp[sum];            // add the new left term
            window -= dp[sum + maxPts];   // remove the old rightmost term
        }

        // Answer is the probability starting from sum 0.
        return dp[0];
    }
};