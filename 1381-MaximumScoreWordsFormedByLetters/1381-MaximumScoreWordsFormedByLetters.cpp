// Last updated: 02/05/2026, 22:40:39
class Solution {
public:
    void solve(int idx, vector<string>& words, unordered_map<char, int>& freq,
               vector<int>& score, int currScore, int& maxScore) {

        // Base case: If we processed all words
        if (idx >= words.size()) {
            maxScore = max(maxScore, currScore);
            return;
        }

        // 1. Not taking the current word
        solve(idx + 1, words, freq, score, currScore, maxScore);

        // 2. Checking if we can take the current word
        bool canTakeWord = true;
        int wordScore = 0;

        for (char ch : words[idx]) {
            if (freq[ch] <= 0) { // Ensure enough frequency
                canTakeWord = false;
            }
            freq[ch]--; // Reduce frequency
            wordScore += score[ch - 'a'];
        }

        if (canTakeWord) {
            solve(idx + 1, words, freq, score, currScore + wordScore, maxScore);
        }

        // *** Backtrack: Restore frequencies ***
        for (char ch : words[idx]) {
            freq[ch]++; // Restore frequency
        }
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        unordered_map<char, int> freq;
        int maxScore = 0;

        // Fill frequency map with available letters
        for (char ch : letters) {
            freq[ch]++;
        }

        solve(0, words, freq, score, 0, maxScore);
        return maxScore;
    }
};