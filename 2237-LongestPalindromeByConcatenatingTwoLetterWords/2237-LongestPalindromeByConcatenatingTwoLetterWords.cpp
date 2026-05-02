// Last updated: 02/05/2026, 22:37:06
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        for (const string& word : words) {
            count[word]++;
        }

        int length = 0;
        bool hasMiddle = false;

        for (auto& [word, freq] : count) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (word != rev && count.count(rev)) {
                int pairCount = min(freq, count[rev]);
                length += pairCount * 4;
                count[word] -= pairCount;
                count[rev] -= pairCount;
            } 
            else if (word == rev) {
                // Count how many pairs we can form from "aa", "dd", etc.
                length += (freq / 2) * 4;
                if (freq % 2 == 1) {
                    hasMiddle = true; // keep one in the middle
                }
            }
        }

        if (hasMiddle) length += 2;

        return length;
    }
};