// Last updated: 02/05/2026, 22:42:17
class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int n = s.length();
        stack<char> st;

        for(int i = 0; i < n; i++){

            if(st.empty()){
                st.push(s[i]);
                continue;
            }

            if(st.top() == '(' && s[i] == ')'){
                st.pop();
            }else{

                st.push(s[i]);
            }
        }

        int min_additions = st.size();

        return min_additions;
    }
};