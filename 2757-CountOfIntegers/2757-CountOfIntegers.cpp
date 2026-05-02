// Last updated: 02/05/2026, 22:34:55
class Solution {
public:
    int solve(int idx, bool tight, int sum, string &s, int min_sum, int max_sum, vector<vector<vector<int>>>& dp){

        int mod = 1e9 + 7; // to handle large cases

        //base case : index out of bounds
        if(idx == s.size()){
            
            //sum of digits is in the required range
            if(sum >= min_sum && sum <= max_sum){
                return 1;
            }
            return 0; // missing this line in your original code
        }

        // Check if sum is already beyond the capacity of dp array
        if(sum >= dp[0][0].size()) {
            // If already beyond max_sum, further digits won't help
            return 0;
        }

        //subproblem already solved
        if(dp[idx][tight][sum] != -1){
            return dp[idx][tight][sum];
        }

        int goodIntegers = 0;

        //calculate limit for current idx
        int limit = tight ? s[idx] - '0' : 9;

        //loop from 0 to limit
        for(int d = 0; d <= limit; d++){

            int newTight = tight & (d == limit);
            goodIntegers = (goodIntegers + solve(idx + 1, newTight, sum + d, s, min_sum, max_sum, dp) % mod) % mod;
        }

        //memoize state
        return dp[idx][tight][sum] = goodIntegers % mod;
    }

    //to check if low itself is valid
    bool isValid(string s, int min_sum, int max_sum) {
        int sum = 0;
        for (char c : s) sum += c - '0';
        return sum >= min_sum && sum <= max_sum;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        
        int num1_size = num1.length();
        int num2_size = num2.length();

        // Calculate maximum possible sum (worst case: all 9's)
        int max_possible_sum = 9 * max(num1_size, num2_size);
        // Use the smaller of max_sum and max_possible_sum for the dp table
        int dp_max_sum = min(max_sum, max_possible_sum);

        vector<vector<vector<int>>> dp1(num1_size + 1, vector<vector<int>>(2, vector<int>(max_possible_sum + 1, -1)));
        vector<vector<vector<int>>> dp2(num2_size + 1, vector<vector<int>>(2, vector<int>(max_possible_sum + 1, -1)));

        int GoodIntegersTillNum1 = solve(0, true, 0, num1, min_sum, max_sum, dp1);
        int GoodIntegersTillNum2 = solve(0, true, 0, num2, min_sum, max_sum, dp2);

        int mod = 1e9 + 7;

        // count num1 itself if it is valid
        int isNum1Valid = isValid(num1, min_sum, max_sum) ? 1 : 0;

        int requiredGoodIntegers = (GoodIntegersTillNum2 - GoodIntegersTillNum1 + isNum1Valid + mod) % mod;

        return requiredGoodIntegers;
    }
};
