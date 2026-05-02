// Last updated: 02/05/2026, 22:40:53
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int, int> dp;
        //dp[i] gives longest subsequence ending at i;

        int maxLen = 1;

        for(int i = 0; i < arr.size(); i++){
            dp[arr[i]] = dp[arr[i] - difference] + 1;
            maxLen = max(maxLen, dp[arr[i]]);
        } 

        return maxLen;


    }
};