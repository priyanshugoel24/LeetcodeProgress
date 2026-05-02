// Last updated: 02/05/2026, 22:39:04
class Solution {
public:
    int f(int ind, string str, unordered_set<string> hash){

        if(ind == str.length()) return 0;

        string subst;
        int res = INT_MIN;

        for(int i = ind; i<str.length(); i++){

            subst = str.substr(ind, i-ind+1);
            if(hash.find(subst) == hash.end()){

                hash.insert(subst);
                res = max(res, f(i+1, str, hash) +1);
                auto it = hash.find(subst);
                if(it != hash.end()) hash.erase(it);
            }
        }

        return res;
    }
    int maxUniqueSplit(string s) {
        int n = s.length();
        unordered_set<string> hash;
        return f(0, s , hash);
        
    }
};