// Last updated: 02/05/2026, 22:45:33
class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n = s.length();

        string result;

        vector<bool> charTaken(26, false);
        vector<int> lastIndex(26);

        for(int i = 0; i < n; i++){

            char ch = s[i];

            lastIndex[ch - 'a'] = i;
        }

        for(int i = 0; i < n; i++){

            char ch = s[i];

            int idx = ch - 'a';

            if(charTaken[idx] == true){
                continue;
            }

            while(result.length() > 0 && result.back() > ch && lastIndex[result.back() - 'a'] > i){
                charTaken[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(ch);
            charTaken[idx] = true;
        }

        return result;
    }
};