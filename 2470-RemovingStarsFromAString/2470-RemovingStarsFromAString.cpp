// Last updated: 02/05/2026, 22:36:07
class Solution {
public:
    string removeStars(string s) {
        
        stack<char> st;

        int n = s.length();

        string result = "";

        for(int i = 0; i < n; i++){

            char ch = s[i];

            if(st.empty()){
                st.push(ch);
                continue;
            }

            if(ch == '*'){
                st.pop();
            }else{
                st.push(ch);
            }
        }

        while(!st.empty()){

            result += st.top();
            st.pop();

        }

        reverse(result.begin(), result.end());

        return result;
    }
};