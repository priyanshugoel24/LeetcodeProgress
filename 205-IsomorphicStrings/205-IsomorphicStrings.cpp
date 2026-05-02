// Last updated: 02/05/2026, 22:46:30
class Solution {
public:
    bool isIsomorphic(string s, string t) {

        map<char,char> st;
        map<char,char> ts;

        int n = s.size();

        for(int i = 0 ; i<n; i++){

            char c1 = s[i];
            char c2 = t[i];

            if((st[c1] and st[c1] != c2) or (ts[c2] and ts[c2] != c1)){
                return false;
            }

            st[c1] = c2;
            ts[c2] = c1;
        }

        return true;
        
    }
};