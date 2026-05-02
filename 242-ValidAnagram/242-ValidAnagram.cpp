// Last updated: 02/05/2026, 22:45:57
class Solution {
public:
    bool isAnagram(string s, string t) {

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return (s == t);
        
    }
};