// Last updated: 02/05/2026, 22:33:11
class Solution {
public:
    char kthCharacter(int k) {

        int n = 1;

        while (k >= pow(2, n)) {
            n++;
        }

        // n is the required length of the string
        string word = "a";

        while (word.length() < k + 1) {
            string temp = word; // Copy current state
            for (char ch : temp) {
                char nextChar =
                    ((ch - 'a' + 1) % 26) + 'a'; // Fix the transformation
                word.push_back(nextChar);
            }
        }

        return word[k-1];
    }
};