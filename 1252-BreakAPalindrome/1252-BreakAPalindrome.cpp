// Last updated: 02/05/2026, 22:41:15
class Solution {
public:
    string breakPalindrome(string s) {
        
        int n = s.length();

        // for a single length string we cannot replace character so that the new string is not palindrome
        if(n == 1){

            return "";
        }

        int i = 0;

        while(i < n/2){

            if(s[i] != 'a'){
                s[i] = 'a';
                return s;
            }

            i++;
        }

        s[n-1] = 'b';

        return s;

    }
};