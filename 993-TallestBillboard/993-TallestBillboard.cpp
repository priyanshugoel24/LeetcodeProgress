// Last updated: 02/05/2026, 22:42:08
class Solution {
public:
    int solve(int idx, int diff, vector<int>& rods, vector<vector<int>>& dp){
        int n = rods.size();

        //base case
        if(idx >= n){

            if(diff == 0){ // billboard can be formed with length l1/l2
                return 0;
            }
            else{ // no possible way of forming billboard
                return INT_MIN;
            }
        }

        // if the subproblem is already solved
        if(dp[idx][diff + 5000] != -1){
            return dp[idx][diff + 5000];
        }

        int maxLength = INT_MIN;

        // don't add current length to any rod
        int skip = solve(idx+1, diff, rods, dp);

        // add length to 1'st rod
        int l1Add = rods[idx] + solve(idx+1, diff + rods[idx] , rods, dp);

        //add length to 2nd rod
        int l2Add = rods[idx] + solve(idx+1, diff - rods[idx], rods, dp);

        // return maximum of all three options
        maxLength = max({skip, l1Add, l2Add});

        return dp[idx][diff + 5000] = maxLength;
    }

    int solveTab(vector<int>& rods) {
        int n = rods.size();
        int totalSum = accumulate(rods.begin(), rods.end(), 0);
        int offset = totalSum;

        vector<vector<int>> dp(n + 1, vector<int>(2 * totalSum + 1, INT_MIN));
        dp[0][offset] = 0;

        for (int i = 0; i < n; i++) {
            for (int diff = 0; diff <= 2 * totalSum; diff++) {
                if (dp[i][diff] == INT_MIN) continue;

                // Option 1: skip the rod
                dp[i + 1][diff] = max(dp[i + 1][diff], dp[i][diff]);

                // Option 2: add rod to left
                int newDiffLeft = diff + rods[i];
                if (newDiffLeft <= 2 * totalSum) {
                    dp[i + 1][newDiffLeft] = max(dp[i + 1][newDiffLeft], dp[i][diff]);
                }

                // Option 3: add rod to right
                int newDiffRight = abs(diff - rods[i]);
                dp[i + 1][newDiffRight] = max(dp[i + 1][newDiffRight], dp[i][diff] + min(rods[i], diff >= rods[i] ? rods[i] : diff));
            }
        }

        return dp[n][offset]; // max height with zero difference
    }

    int tallestBillboard(vector<int>& rods) {
        
        int n = rods.size();

        int l1 = 0; // length of 1st rod
        int l2 = 0; // length of 2nd rod
        int diff = l1 - l2; // diff of lengths of two rods

        // vector<vector<int>> dp(n, vector<int>(10003, -1));

        // int totalLengthUsed = solve(0, diff, rods, dp);

        return solveTab(rods);

        // int lengthOfRod = totalLengthUsed/2; // length of single rod is half of total length of 2 rods

        // return lengthOfRod;

    }
};