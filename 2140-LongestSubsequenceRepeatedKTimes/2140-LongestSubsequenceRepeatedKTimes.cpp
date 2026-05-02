// Last updated: 02/05/2026, 22:37:41
class Solution {
public:
    bool isSubsequence(const string &s, const string &sub, int k) {
        int i = 0, j = 0;
        int len = sub.length(), n = s.length();

        while (i < n && j < k * len) {
            if (s[i] == sub[j % len]) {
                j++;
            }
            i++;
        }

        return j == k * len;
    }

    void backtracking(const string &s, string &curr, vector<bool> &candidate, vector<int> &requiredFreq,
                      int k, int maxLen, string &result) {

        if (curr.length() > maxLen) return;

        if ((curr.length() > result.length() || (curr.length() == result.length() && curr > result)) &&
            isSubsequence(s, curr, k)) {
            result = curr;
        }

        for (int i = 25; i >= 0; --i) {  // Start from 'z' to 'a' for lexicographically larger result
            if (!candidate[i] || requiredFreq[i] == 0) continue;

            char ch = 'a' + i;
            curr.push_back(ch);
            requiredFreq[i]--;

            backtracking(s, curr, candidate, requiredFreq, k, maxLen, result);

            curr.pop_back();
            requiredFreq[i]++;
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);

        for (char ch : s) freq[ch - 'a']++;

        vector<bool> candidate(26, false);
        vector<int> requiredFreq(26, 0);

        for (int i = 0; i < 26; ++i) {
            if (freq[i] >= k) {
                candidate[i] = true;
                requiredFreq[i] = freq[i] / k;
            }
        }

        int maxLen = n / k;

        string curr, result;
        backtracking(s, curr, candidate, requiredFreq, k, maxLen, result);

        return result;
    }
};
