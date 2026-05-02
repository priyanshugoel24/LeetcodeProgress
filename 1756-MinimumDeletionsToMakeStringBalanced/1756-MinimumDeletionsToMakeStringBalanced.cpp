// Last updated: 02/05/2026, 22:38:54
class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.length();
        stack<char> st;

        int min_deletions = 0;

        for(int i = 0; i < n; i++){

            if(st.empty()){
                st.push(s[i]);
                continue;
            }

            if(st.top() == 'b' && s[i] == 'a'){
                st.pop();
                min_deletions++;
            }else{
                st.push(s[i]);
            }

        }

        return min_deletions;
    }
};