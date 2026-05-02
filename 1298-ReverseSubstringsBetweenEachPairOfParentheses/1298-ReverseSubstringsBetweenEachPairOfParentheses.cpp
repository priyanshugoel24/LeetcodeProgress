// Last updated: 02/05/2026, 22:41:02
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<string> st;
        st.push(""); // Initialize with an empty string to build on

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                // Start a new substring context
                st.push("");
            } else if (s[i] == ')') {
                // Complete the current context
                string top = st.top(); st.pop();
                reverse(top.begin(), top.end());
                st.top() += top; // Append reversed string to previous level
            } else {
                // Regular character, append to current string
                st.top().push_back(s[i]);
            }
        }

        return st.top(); // Final assembled string
    }
};
