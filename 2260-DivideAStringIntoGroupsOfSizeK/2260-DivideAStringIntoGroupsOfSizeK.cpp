// Last updated: 02/05/2026, 22:37:01
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        
        int n = s.length();
        int fill_to_add = k - (n % k);

        while(fill_to_add > 0){
            s += fill;
            fill_to_add--;
        }

        vector<string> result;

        int i = 0;
        int K = k;
        while(i < n){

            string curr = "";
            while(K--){
                curr += s[i];
                i++;
            }
            result.push_back(curr);
            K = k;

        }

        return result;
    }
};