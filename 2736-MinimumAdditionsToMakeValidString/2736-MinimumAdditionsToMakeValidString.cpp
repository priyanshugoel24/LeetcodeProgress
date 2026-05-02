// Last updated: 02/05/2026, 22:34:58
class Solution {
public:
    int addMinimum(string word) {
        
        string pattern = "abc";
        
        int i = 0; // word pointer
        int j = 0; // pattern pointer

        int min_additions = 0;

        int n = word.length();
        
        while(i < n){

            if(word[i] == pattern[j]){
                i++;
                j = (j+1) % 3;
                continue;
            }

            min_additions++;
            j = (j + 1) % 3;
        }

        if(word[n - 1] == 'b'){
            min_additions += 1;
        }else if(word[n - 1] == 'a'){
            min_additions += 2;
        }

        return min_additions;
    }
};