// Last updated: 02/05/2026, 22:32:42
class Solution {
public:
    string findValidPair(string s) {
       unordered_map<char, int> cnt;
    
    // First count frequency of all digits
    for (char ch : s) {
        cnt[ch]++;
    }
    
    // Now check adjacent pairs from left to right
    for (int i = 0; i < s.length() - 1; i++) {
        char first = s[i];
        char second = s[i + 1];
        
        // Check if they are different digits
        if (first != second) {
            // Check if both digits appear exactly their value number of times
            if (cnt[first] == (first - '0') && cnt[second] == (second - '0')) {
                return string() + first + second;
            }
        }
    }
    
    return "";
    }
};