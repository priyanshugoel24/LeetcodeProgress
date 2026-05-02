// Last updated: 02/05/2026, 22:40:10
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(3, 0);
        int left = 0, result = 0;

        for(int i = 0; i<s.length(); i++){
            count[s[i] - 'a']++;

            while(count[0] > 0 && count[1] > 0 && count[2] > 0){
                result += s.length() - i;
                count[s[left] - 'a']--;
                left++;

            }
        }

        return result;

    }
};