// Last updated: 02/05/2026, 22:47:51
class Solution {
public:
    bool solve(int idx_s1, int idx_s2, int idx_s3, string& s1, string& s2, string& s3, vector<vector<vector<int>>>& dp){

        //base case : string s3 is matched completely and s1 and s2 are traversed completely
        if(idx_s3 >= s3.length() && idx_s1 >= s1.length() && idx_s2 >= s2.length()){
            return true;
        }

        //if subproblem is already solved
        if(dp[idx_s1][idx_s2][idx_s3] != -1){
            return dp[idx_s1][idx_s2][idx_s3];
        }

        bool interleavingPossible = false;

        //if char matches from both s1 and s2
        if(idx_s1 < s1.length() && idx_s2 < s2.length() && s3[idx_s3] == s1[idx_s1] && s3[idx_s3] == s2[idx_s2]){

            interleavingPossible = interleavingPossible || solve(idx_s1 + 1, idx_s2, idx_s3 + 1,  s1, s2, s3, dp);
            interleavingPossible = interleavingPossible || solve(idx_s1, idx_s2 + 1, idx_s3 + 1,  s1, s2, s3, dp);
        }

        //if char matches only with s1
        else if(idx_s1 < s1.length() && s3[idx_s3] == s1[idx_s1]){
            interleavingPossible = interleavingPossible || solve(idx_s1 + 1, idx_s2, idx_s3 + 1, s1, s2, s3, dp);
        }

        //if char matches only with s2
        else if(idx_s2 < s2.length() && s3[idx_s3] == s2[idx_s2]){
            interleavingPossible = interleavingPossible || solve(idx_s1, idx_s2 + 1, idx_s3 + 1, s1, s2, s3, dp);
        }

        //memoize the result
        return dp[idx_s1][idx_s2][idx_s3] = interleavingPossible;
    }

    bool solveTab(string s1, string s2, string s3){
        int s1_length = s1.length();
        int s2_length = s2.length();
        int s3_length = s3.length();

        // if length of s1 + length of s2 is not equal to length of s3 interleaving is not possible
        if(s1_length + s2_length != s3_length){
            return false;
        }

        vector<vector<int>> dp(s1_length + 1, vector<int>(s2_length + 1, 0)); // tabulation vector
        //dp[i][j] -> is interleaving possible till s3[i + j -1] using s1[0....i] and s2[0...j]

        //base case : empty string s3 can be made using empty string s1 and s3
        dp[0][0] = true;

        for(int idx_s1 = 0; idx_s1 <= s1_length; idx_s1++){

            for(int idx_s2 = 0; idx_s2 <= s2_length; idx_s2++){
                
                //skip the base case
                if(idx_s1 == 0 && idx_s2 == 0){
                    continue;
                }
                
                //index of s3
                int idx_s3 = idx_s1 + idx_s2 -1;

                bool interleavingPossible = false;

                //case 1 : match char from s1
                if(idx_s1 > 0 && s1[idx_s1 - 1] == s3[idx_s3]){
                    interleavingPossible = interleavingPossible || dp[idx_s1 -1][idx_s2];
                }

                //case 2: match char from s2
                if(idx_s2 > 0 && s2[idx_s2 - 1] == s3[idx_s3]){
                    interleavingPossible = interleavingPossible || dp[idx_s1][idx_s2 -1];
                }

                dp[idx_s1][idx_s2] = interleavingPossible;
            }
        }

        return dp[s1_length][s2_length];
    
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        // int s1_length = s1.length();
        // int s2_length = s2.length();
        // int s3_length = s3.length();

        // vector<vector<vector<int>>> dp(s1_length+1, vector<vector<int>>(s2_length+1, vector<int>(s3_length+1, -1))); // memoization vector

        // return solve(0, 0, 0, s1, s2, s3, dp);

        return solveTab(s1, s2, s3);
    }
};