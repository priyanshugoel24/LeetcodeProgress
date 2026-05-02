// Last updated: 02/05/2026, 22:33:37
class Solution {
public:
    bool isVowel(char ch){

        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'u' || ch == 'o' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
    bool isValid(string word) {        

        int n = word.length();

        // min length check
        if(n < 3){
            return false;
        }

        bool vowelCheck = false;
        bool consonantCheck = false;

        for(int i = 0; i < n; i++){

            char ch = word[i];

            bool letterCheck = (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');

            if(!isdigit(ch) && !letterCheck){
                return false;
            }

            if(isdigit(ch)){
                continue;
            }

            if(isVowel(ch)){
                vowelCheck = true;
            }else{
                consonantCheck = true;
            }
        }

        bool validString = vowelCheck && consonantCheck;

        return validString;

    }
};