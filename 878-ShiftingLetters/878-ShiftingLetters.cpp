// Last updated: 02/05/2026, 22:42:50
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {

        //updating the shifts array to calculate total change
        for(int i = shifts.size()-2; i>=0; i--){
            shifts[i] = (shifts[i] + (shifts[i+1]) % 26) % 26;
        }

        for(int i = 0; i<s.size(); i++){
            int shiftValue = (s[i]-'a' + shifts[i]) % 26;
            s[i] = 'a' + shiftValue;
        }

        return s;
        
    }
};