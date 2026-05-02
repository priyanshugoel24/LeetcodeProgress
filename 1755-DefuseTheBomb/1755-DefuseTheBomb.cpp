// Last updated: 02/05/2026, 22:38:55
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();
        vector<int> res(n, 0);

        if(k == 0) return res;

        int l = 0, currSum = 0;

        for(int r = 0; r < n + abs(k); r++){
            currSum += code[r %n];

            if(r-l + 1 > abs(k)){
                currSum -= code[l %n];
                l = (l + 1) %n;
            }

            if(r-l+1 == abs(k)){
                if(k > 0) res[(l-1+n) %n] = currSum;
                else if(k < 0) res[(r+1) % n] = currSum;
            }
        }
        

        return res;
    }
};