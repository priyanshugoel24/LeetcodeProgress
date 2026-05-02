// Last updated: 02/05/2026, 22:37:05
class Solution {
public:
    bool checkString(string s) {

        for(int i = 0; i<s.length(); i++){
            if(s[i] == 'b' && s[i+1] == 'a') return false;
        }

        return true;
        
    }
};