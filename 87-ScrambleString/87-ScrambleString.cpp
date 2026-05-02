// Last updated: 02/05/2026, 22:47:59
class Solution {
public:
    bool solve(string s1, string s2, unordered_map<string, bool>& mp){

        // Base case: If strings are equal, they are trivially scrambled versions
        if(s1 == s2) return true;
        if(s1.length() != s2.length()) return false;

        // Check if characters and their frequencies are the same
        string key = s1 + "_" + s2;
        if(mp.find(key) != mp.end()) return mp[key];

        int n = s1.length();

        // Frequency check (important optimization)
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) return mp[key] = false;
        }

        // Trying all possible splits
        bool result = false;
        for(int i = 1; i < n; i++){

            // Case 1: Without swapping
            bool not_swapped = solve(s1.substr(0, i), s2.substr(0, i), mp) 
                            && solve(s1.substr(i, n-i), s2.substr(i, n-i), mp);
            if(not_swapped){
                result = true;
                break;
            }

            // Case 2: With swapping
            bool swapped = solve(s1.substr(0, i), s2.substr(n-i, i), mp) 
                         && solve(s1.substr(i, n-i), s2.substr(0, n-i), mp);
            if(swapped){
                result = true;
                break;
            }
        }

        return mp[key] = result;
    }

    
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> mp;
        return solve(s1, s2, mp);
    }
};
