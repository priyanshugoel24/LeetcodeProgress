// Last updated: 02/05/2026, 22:39:58
class Solution {
public:
    bool canConstruct(string s, int k) {
        
        int n = s.length();

        if(k == n) return true;
        if(k > n) return false;

        unordered_map<char,int> freq;

        for(auto &ch : s){
            freq[ch]++;
        }

        int oddCharCount = 0;

        for(auto it : freq){
            char ch = it.first;
            int count = it.second;

            if(count % 2 != 0) oddCharCount++;
        }

        return oddCharCount <= k;

       

        
    }
};