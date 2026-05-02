// Last updated: 02/05/2026, 22:36:08
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        int n = s.length();
        vector<int> diff(n, 0);
        
        //step1 : building the difference array
        for(auto& query : shifts){
            int L = query[0], R = query[1];
            int dir = query[2];
            int x;
            if(dir == 0) x = -1;
            if(dir == 1) x = +1;

            diff[L] += x;
            if(R + 1 < n) diff[R+1] -= x;
        }

        //step2 : find cumulative sum to find resultant change

        for(int i = 1; i<n; i++){
            diff[i] += diff[i-1];
        }

        //step3 : applying the shfit
        for(int i = 0; i<n; i++){
            int shift = diff[i] % 26; // wrap around

            if(shift < 0){
                shift += 26; // wrap around
            }

            int shiftValue = (s[i]-'a' + shift) % 26;
            s[i] = 'a' + shiftValue;

        }

        return s;

       

        
    }
};