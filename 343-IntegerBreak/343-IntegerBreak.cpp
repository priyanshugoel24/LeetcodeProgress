// Last updated: 02/05/2026, 22:45:20
class Solution {
public:
    int solve(int num, vector<int>& dp){

        //base case : if num == 2/1 max product we can achieve is 1 by breaking into 2
        if(num == 2 || num == 1){
            return 1;
        }

        //if the subproblem is already solved
        if(dp[num] != -1){
            return dp[num];
        }

        int maxProductPossible = 1; // maxProduct possible for a given integer

        for(int k = 1 ; k <= num/2 ; k++){
            
            //split the number into two parts k and num - k
            int part1 = max(k, solve(k, dp));
            int part2 = max(num - k, solve(num - k, dp));

            //find the product with this combination
            int currProduct = part1 * part2;

            //update the maximum possible product
            maxProductPossible = max(maxProductPossible, currProduct);
        }

        //memoize the maximum possible product
        return dp[num] = maxProductPossible;
    }

    int solveTab(int n){

        vector<int> dp(n+1, 1); // tabulation vector

        for(int num = 3; num <= n; num++){

            int maxProductPossible = 1;

            for(int k = 1 ; k <= num / 2 ; k++){

                int part1 = k;
                int part2 = max(num - k, dp[num - k]);

                int currProduct = part1 * part2;

                maxProductPossible = max(maxProductPossible, currProduct);
            }

            dp[num] = maxProductPossible;
        }

        return dp[n];
    }
    int integerBreak(int n) {
        
        vector<int> dp(n + 1, -1);
        return solve(n, dp);

        // return solveTab(n);
    }
};