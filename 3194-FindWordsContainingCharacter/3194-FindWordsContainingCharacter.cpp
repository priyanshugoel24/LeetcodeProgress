// Last updated: 02/05/2026, 22:34:15
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        
        vector<int> result;

        for(int i = 0; i < words.size(); i++){

            string word = words[i];

            bool charPresent = false;
            for(char ch : word){

                if(ch == x){
                    charPresent = true;
                    break;
                }
            }

            if(charPresent) result.push_back(i);
        }

        return result;
    }
};