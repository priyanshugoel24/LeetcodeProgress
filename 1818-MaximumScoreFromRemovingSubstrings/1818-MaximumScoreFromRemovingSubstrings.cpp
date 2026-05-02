// Last updated: 02/05/2026, 22:38:45
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        string first_to_remove = (x > y) ? "ab" : "ba";
        string second_to_remove = (x > y) ? "ba" : "ab";
        int first = max(x, y);
        int second = min(x, y);

        int max_points = 0;
        stack<char> st;

        // First pass: remove more valuable pattern
        string intermediate = "";
        for (char ch : s) {
            if (!st.empty() && st.top() == first_to_remove[0] && ch == first_to_remove[1]) {
                st.pop();
                max_points += first;
            } else {
                st.push(ch);
            }
        }

        // create second string for parsing
        while (!st.empty()) {
            intermediate += st.top();
            st.pop();
        }
        reverse(intermediate.begin(), intermediate.end());

        // Second pass: remove remaining pattern
        for (char ch : intermediate) {
            if (!st.empty() && st.top() == second_to_remove[0] && ch == second_to_remove[1]) {
                st.pop();
                max_points += second;
            } else {
                st.push(ch);
            }
        }

        return max_points;
    }
};
