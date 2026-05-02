// Last updated: 02/05/2026, 22:37:11
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();

        if(n%2 == 1) return false;

        int open = 0; // L to R

        for(int i = 0; i<n; i++){
            if(s[i] == '(' || locked[i] == '0'){
                open++;
            } else{
                open--;
            }

            if(open < 0) return false;

        }

        

        //R to L
        int close = 0;

        for(int i = n-1; i>=0; i--){
            if(s[i] == ')' || locked[i] == '0'){
                close++;
            } else{
                close--;
            }

            if(close < 0) return false;
        }

        

        return true;
        
    }
};