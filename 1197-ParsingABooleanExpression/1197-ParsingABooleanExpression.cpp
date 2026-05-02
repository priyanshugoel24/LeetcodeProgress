// Last updated: 02/05/2026, 22:41:29
class Solution {
public:
    char evaluate(vector<bool>& v, char op) {
        bool result;

        switch(op) {
            case '&':
                result = true;
                for(bool val : v) result &= val;
                break;
            case '|':
                result = false;
                for(bool val : v) result |= val;
                break;
            case '!':
                result = !v[0];  // only one operand
                break;
        }

        return result ? 't' : 'f';
    }

    bool parseBoolExpr(string s) {
        stack<char> st;

        for(char c : s) {
            if(c == ',') continue;

            if(c == ')') {
                vector<bool> vals;

                while(!st.empty() && st.top() != '(') {
                    char top = st.top(); st.pop();
                    vals.push_back(top == 't');
                }

                st.pop(); // pop '('

                char op = st.top(); st.pop();  // pop operator before '('
                char res = evaluate(vals, op);
                st.push(res);
            } 
            else {
                st.push(c);  // push '(', 't', 'f', or operators
            }
        }

        return st.top() == 't';
    }
};
