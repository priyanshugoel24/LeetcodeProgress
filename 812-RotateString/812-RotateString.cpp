// Last updated: 02/05/2026, 22:43:13
class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length() != goal.length()) return false;

        string doubled = s + s;
        return doubled.find(goal) != string::npos;


        
    }
};
