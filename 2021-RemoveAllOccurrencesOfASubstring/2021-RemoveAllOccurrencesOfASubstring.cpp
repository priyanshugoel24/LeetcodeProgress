// Last updated: 02/05/2026, 22:38:06
class Solution {
public:
    string removeOccurrences(string s, string part) {

        while(s.length() != 0 && s.find(part) < s.length()){
            s.erase(s.find(part), part.length());
        }

        return s;       
        
    }
};