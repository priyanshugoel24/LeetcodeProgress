// Last updated: 02/05/2026, 22:38:23
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        if(s1 == s2) return true;

        //string should not match only at 2 places and the characters not matching should be same in both places

        int notMatching = 0;

        int firstidx = -1, secondidx = -1;

        for(int i = 0; i<s1.length(); i++){
            if(s1[i] != s2[i]){
                notMatching++;
                if(firstidx != -1) secondidx = i;
                else firstidx = i;
            }
            

        }

        if(notMatching != 2) return false;

        if(s1[firstidx] != s2[secondidx] || s1[secondidx] != s2[firstidx]) return false;

        return true;




        
    }
};