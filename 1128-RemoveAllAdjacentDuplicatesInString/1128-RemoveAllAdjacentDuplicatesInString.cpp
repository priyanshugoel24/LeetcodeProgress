// Last updated: 02/05/2026, 22:41:42
class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char> st;

       for(int i = 0; i < s.length(); i++){

        char ch = s[i];

        if(st.empty()){
            st.push(ch);
            continue;
        }

        if(ch == st.top()){
            st.pop();

        }else{
            st.push(ch);
        }
       }
        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};