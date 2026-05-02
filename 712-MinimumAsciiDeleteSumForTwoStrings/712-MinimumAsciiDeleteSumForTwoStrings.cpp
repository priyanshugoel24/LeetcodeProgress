// Last updated: 02/05/2026, 22:43:43
class Solution {
public:
    int solve(int idx_s1, int idx_s2, string& s1, string& s2, int& s1_length, int& s2_length, vector<vector<int>>& dp){

        //base case : both strings out of bound
        if(idx_s1 >= s1_length && idx_s2 >= s2_length){
            return 0;
        }        

        //base case : idx of s1/s2 is out of bound
        if(idx_s1 >= s1_length){

            return s2[idx_s2] + solve(idx_s1, idx_s2+1, s1, s2, s1_length, s2_length, dp);
        }else if(idx_s2 >= s2_length){

            return s1[idx_s1] + solve(idx_s1 + 1, idx_s2, s1, s2, s1_length, s2_length, dp);
        }

        // case 1 : character of both strings match
        if(s1[idx_s1] == s2[idx_s2]){
            return 0 + solve(idx_s1 + 1, idx_s2 + 1, s1, s2, s1_length, s2_length, dp);
        }

        // if subproblem is already solved
        if(dp[idx_s1][idx_s2] != -1){

            return dp[idx_s1][idx_s2];
        }

        //case 2 : character of both strings do not match

        //option1 : increment idx_s1
        int delete_from_s1 = s1[idx_s1] + solve(idx_s1 + 1, idx_s2, s1, s2, s1_length, s2_length, dp);

        //option2 : increment idx_s2
        int delete_from_s2 = s2[idx_s2] + solve(idx_s1, idx_s2 + 1, s1, s2, s1_length, s2_length, dp);

        //memoize state
        return dp[idx_s1][idx_s2] = min(delete_from_s1, delete_from_s2);
    }
    int minimumDeleteSum(string s1, string s2) {
        
        int s1_length = s1.length(); //length of string s1
        int s2_length = s2.length(); //length of string s2

        vector<vector<int>> dp(s1_length, vector<int>(s2_length, -1)); //memoization array

        return solve(0, 0, s1, s2, s1_length, s2_length, dp);
    }
};