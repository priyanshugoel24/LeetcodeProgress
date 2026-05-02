// Last updated: 02/05/2026, 22:49:05
class Solution {
public:
    bool isValid(string s) {
        
        int n = s.length();

        stack<char> st;

        for(int i = 0; i < n; i++){

            char ch = s[i];
            if(st.empty() || ch == '(' || ch == '{'  || ch == '['){
                st.push(ch);
                continue;
            }

            char top = st.top();
            
            bool firstCondn = ch == ')' && top != '(';
            bool secondCondn = ch == '}' && top != '{';
            bool thirdCondn = ch == ']' && top != '[';

            if(firstCondn || secondCondn || thirdCondn){
                return false;
            }else{
                st.pop();
            }
        }

        bool finalCondn = st.empty();

        return finalCondn;
    }
};