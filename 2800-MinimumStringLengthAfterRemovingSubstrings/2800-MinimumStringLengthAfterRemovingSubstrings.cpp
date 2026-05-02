// Last updated: 02/05/2026, 22:34:49
class Solution {
public:
    int minLength(string s) {

        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
         if(st.empty())
         {
            st.push(ch);
            continue;
         }
            if ((st.top() == 'A' && ch == 'B') ||
                (st.top() == 'C' && ch == 'D')) {
                st.pop();
            }

            else {
                st.push(ch);
            }
        }

        return st.size();
    }
};