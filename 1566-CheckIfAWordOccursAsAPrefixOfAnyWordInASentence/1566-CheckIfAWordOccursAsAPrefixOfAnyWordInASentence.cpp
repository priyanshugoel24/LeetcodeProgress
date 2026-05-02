// Last updated: 02/05/2026, 22:39:36
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream s(sentence);
        string t;
        for(int i = 1; s >> t; i++)
            if(t.substr(0, searchWord.length()) == searchWord) return i;
        return -1;
    }
};