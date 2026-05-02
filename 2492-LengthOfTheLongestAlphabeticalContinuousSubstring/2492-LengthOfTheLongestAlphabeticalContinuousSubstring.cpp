// Last updated: 02/05/2026, 22:36:00
class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        int n = s.length();

        int max_length = 1;
        int length = 1;

        for(int i = 1; i < n; i++){

            if(s[i] == s[i - 1] + 1){
                length++;
            }else{
                length = 1;
            }
            
            max_length = max(max_length, length);
        }

        return max_length;
    }
};