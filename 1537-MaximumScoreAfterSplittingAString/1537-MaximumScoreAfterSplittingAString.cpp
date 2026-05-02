// Last updated: 02/05/2026, 22:39:44
class Solution {
public:
    int maxScore(string s) {

        int one = 0, zero = 0, ans = 0;

        for(int i = 1; i < s.size(); i++){
            if(s[i] == '1') one++;
        }

        for(int i = 1; i<s.size(); i++){
            if(s[i-1] == '0') zero++;
            ans = max(ans, one + zero);
            if(s[i] == '1') one--;
        }
        
        return ans;
    }
};