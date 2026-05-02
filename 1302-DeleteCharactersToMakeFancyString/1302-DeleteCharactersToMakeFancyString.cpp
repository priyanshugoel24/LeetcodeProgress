// Last updated: 02/05/2026, 22:41:01
class Solution {
public:
    string makeFancyString(string s) {
        
        int n = s.length();

        // if length is less than 3 no deletions needed, already a fancy string
        if(n < 3){
            return s;
        }

        int i = 2, j = 2;

        while(i < n && j < n){

            if(s[i] != s[j - 1] || s[i] != s[j - 2]){
                s[j++] = s[i];
            }

            i++;
        }

        s.resize(j);

        return s;
    }
};