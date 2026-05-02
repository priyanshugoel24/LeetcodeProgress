// Last updated: 02/05/2026, 22:34:27
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        
        int n = groups.size(); // size of groups array == size of words array

        vector<string> longestSubsequence; // longest subsequence of string that satisfy condition

        for(int i = 0; i < n ; ++i){

            //case 1 : we can always form a subsequence with first element so we don't need to compare it with any
            if(i == 0){
                longestSubsequence.push_back(words[i]);
                continue;
            }

            //case 2 : if we find alternating bit in groups array, we can start a new subsequence and pick the first element for that

            if(groups[i] != groups[i - 1]){

                longestSubsequence.push_back(words[i]);
            }
        }

        //return the final valid subsequence
        return longestSubsequence;
    }
};