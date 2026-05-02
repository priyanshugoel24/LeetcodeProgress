// Last updated: 02/05/2026, 22:33:28
class Solution {
public:
    string clearDigits(string s) {

        int n = s.length();

        int i = 0, j = 0;

        while(i < n){
            if(isdigit(s[i])){
                j = max(j-1,0); // to prevent j from going negative
                // in future if i finds valid character, we will replace j with that
            }else{
                s[j] = s[i];
                j++;
            }

            i++;
        }

        return s.substr(0, j);

    
        
    }
};