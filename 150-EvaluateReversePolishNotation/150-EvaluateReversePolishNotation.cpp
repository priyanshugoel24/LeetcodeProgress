// Last updated: 02/05/2026, 22:46:59
class Solution {
public:
    bool isInteger(const string& s) {
        if (s.empty()) return false;
        int start = (s[0] == '-' || s[0] == '+') ? 1 : 0;
        return start < s.size() && all_of(s.begin() + start, s.end(), ::isdigit);
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            if (isInteger(token)) {
                st.push(stoi(token));
            } else {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                int result = 0;

                if (token == "+") result = num2 + num1;
                else if (token == "-") result = num2 - num1;
                else if (token == "*") result = num2 * num1;
                else if (token == "/") result = num2 / num1;

                st.push(result);
            }
        }

        return st.top();
    }
};
