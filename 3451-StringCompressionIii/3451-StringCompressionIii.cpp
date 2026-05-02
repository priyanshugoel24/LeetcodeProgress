// Last updated: 02/05/2026, 22:33:26
class Solution {
public:
    string compressedString(string word) {

        string comp = "";        
        int charCount = 1;

        for(int i = 0; i<word.length(); i++){

           if(word[i+1] == word[i] && charCount < 9){
            charCount++;
            continue;
           }
           else{
            
            comp += to_string(charCount);
            comp += word[i];
            charCount = 1;

           }
        }

        return comp;
        
    }
};