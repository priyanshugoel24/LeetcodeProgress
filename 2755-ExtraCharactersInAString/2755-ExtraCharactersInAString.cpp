// Last updated: 02/05/2026, 22:34:56
class Solution {
public:
    int solve(int idx, string& s, unordered_set<string>& words, vector<int>& dp){
        int n = s.length();
        //base case : index out of bounds
        if(idx >= s.length()){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        string currString = "";
        int minExtra = n;

        for(int i = idx; i < n; i++){

            currString.push_back(s[i]);

            int currExtra = (words.find(currString) == words.end()) ? currString.length() : 0;

            int nextExtra = solve(i+1, s, words, dp);

            int totalExtra = currExtra + nextExtra;

            minExtra = min(minExtra, totalExtra);
        }

        return dp[idx] = minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        
        int n = s.length();

        vector<int> dp(n + 1, -1); //memoization vector

        unordered_set<string> words; // words in dictionary

        for(string &word : dictionary){
            words.insert(word);
        }

        return solve(0, s, words, dp);

    }
};