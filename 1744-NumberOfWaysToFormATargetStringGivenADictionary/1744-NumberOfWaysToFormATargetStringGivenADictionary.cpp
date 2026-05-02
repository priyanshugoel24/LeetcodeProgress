// Last updated: 02/05/2026, 22:38:57
class Solution {
public:
    int solve(int i, int k, vector<string>& words, string target,
              vector<vector<int>>& dp) {
        int mod = 1e9 + 7;
        // base case
        if (i == target.length()) { // target is formed completely
            return 1;
        }

        if (k == words[0].length() &&
            i != target.length()) { // target string could not be formed
            return 0;
        }

        if (dp[i][k] != -1)
            return dp[i][k];

        int possibleWays = 0;

        int matchCount = 0;

        // checking for every string if target[i] matches word[k];
        for (int j = 0; j < words.size(); j++) {

            string word = words[j];

            if (word[k] == target[i]) { // there is a match
                matchCount++;
            }
        }

        // option1 : don't match the current character
        possibleWays = solve(i, k + 1, words, target, dp) % mod;

        // option2 : if matchCount > 0 match the current character

        if (matchCount > 0) {
            possibleWays =
                (possibleWays +
                 (1LL * matchCount * solve(i + 1, k + 1, words, target, dp)) %
                     mod) %
                mod;
        }

        return dp[i][k] = possibleWays % mod;
    }

    int solveTab(vector<string>& words, string target) {
        int mod = 1e9+7;
        int target_length = target.length();
        int word_length = words[0].length();

        vector<vector<int>> dp(target_length + 1,
                               vector<int>(word_length + 1, 0));

        for (int i = 0; i <= word_length; i++) {
            dp[target_length][i] = 1;
        }

        vector<vector<int>> freq(26, vector<int>(word_length, 0));
for (const string& word : words) {
    for (int k = 0; k < word_length; k++) {
        freq[word[k] - 'a'][k]++;
    }
}


        for (int i = target_length - 1; i >= 0; i--) {
            for (int k = word_length -1; k >= 0; k--) {

                int possibleWays = 0;

                // checking for every string if target[i] matches word[k];
               int matchCount = freq[target[i] - 'a'][k]; // fast lookup instead of looping


                // option1 : don't match the current character
                possibleWays = dp[i][k+1] % mod;

                // option2 : if matchCount > 0 match the current character

                if (matchCount > 0) {
                    possibleWays = (possibleWays +
                                    (1LL * matchCount *
                                     dp[i+1][k+1]) %
                                        mod) %
                                   mod;
                }


                dp[i][k] = possibleWays;
            }            
        }

        return dp[0][0];
    }
    int numWays(vector<string>& words, string target) {
        int target_length = target.length();
        int word_length = words[0].length();

        // vector<vector<int>> dp(target_length + 1,
        //                        vector<int>(word_length + 1, -1));
        // return solve(0, 0, words, target, dp);

        return solveTab(words, target);
    }
};