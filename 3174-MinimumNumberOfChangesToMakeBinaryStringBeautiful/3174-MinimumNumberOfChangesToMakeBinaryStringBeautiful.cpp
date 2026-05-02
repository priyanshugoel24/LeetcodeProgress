// Last updated: 02/05/2026, 22:34:20
class Solution {
public:
    int minChanges(string s) {
        int swaps = 0;
        int currCount = 1;
        char currChar = s[0];

        for(int i = 1; i<s.length(); i++){
            if(s[i] == currChar) currCount++;
            else{
                if(currCount % 2 != 0){
                    swaps++;
                    currCount++;
                }
                else{
                    currChar = s[i];
                    currCount = 1;
                }
            }
        }

        return swaps;
        
    }
};