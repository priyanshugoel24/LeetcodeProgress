// Last updated: 02/05/2026, 22:33:09
class Solution {
public:
    int possibleStringCount(string word) {
        
        int n = word.length();

        int possible_strings = 0;

        for(int i = 1; i < n ; i++){
            
            if(word[i] == word[i - 1]){
                possible_strings++;
            }
        }

        possible_strings += 1; // if no mistake was there

        return possible_strings;
    }
};