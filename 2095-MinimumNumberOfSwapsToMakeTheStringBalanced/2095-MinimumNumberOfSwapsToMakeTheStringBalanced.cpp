// Last updated: 02/05/2026, 22:37:48
class Solution {
public:
    int minSwaps(string s) {
        
        int n = s.length();

        int unbalanced_opening_brackets = 0;

        for(int i = 0; i < n; i++){

            if(s[i] == '['){
                unbalanced_opening_brackets++;
            }else if(s[i] == ']' && unbalanced_opening_brackets != 0){
                unbalanced_opening_brackets--;
            }
        }

        int min_swaps = (unbalanced_opening_brackets + 1) / 2;

        return min_swaps;
    }
};