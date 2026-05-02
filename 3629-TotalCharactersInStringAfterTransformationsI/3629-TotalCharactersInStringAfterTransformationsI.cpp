// Last updated: 02/05/2026, 22:33:03
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        
        int mod = 1e9 + 7;

        int len = s.size();
        int z = 25;

        unordered_map<int , long long> freq;
        
        for(char ch : s){
            freq[ch - 'a']++;
        }

        while(t--){
            len = (len + freq[z]) % mod;
            freq[(z + 1) % 26] = (freq[(z + 1) % 26] + freq[z]) % mod;
            z = (z + 25) % 26;
        }

        return len;
    }
};