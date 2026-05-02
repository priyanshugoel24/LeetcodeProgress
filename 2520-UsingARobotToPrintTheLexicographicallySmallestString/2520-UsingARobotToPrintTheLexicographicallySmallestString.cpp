// Last updated: 02/05/2026, 22:35:50
class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        string p = "";
        stack<char> t;

        // Find the minimum char from right to left
        vector<char> min_right(n);
        min_right[n - 1] = s[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            min_right[i] = min(s[i], min_right[i + 1]);
        }

        int i = 0;
        while (i < n) {
            t.push(s[i]);

            // Greedily pop from t if its top is <= min_right[i + 1]
            while (!t.empty() && (i == n - 1 || t.top() <= min_right[i + 1])) {
                p += t.top();
                t.pop();
            }

            i++;
        }

        // Add any remaining chars
        while (!t.empty()) {
            p += t.top();
            t.pop();
        }

        return p;
    }
};
