// Last updated: 02/05/2026, 22:33:59
class Solution {
public:
    int maximumLength(string s) {

        map<pair<char,int>, int> mp;

        for(int i = 0; i<s.length(); i++){
            char ch = s[i];
            int l = 0;
            
            for(int j = i; j<s.length(); j++){
                if(s[j] == ch){
                    l++;
                    mp[{ch, l}]++;
                } else break;
            }
        }

        int result = -1;

        for(auto &it : mp){
            char ch = it.first.first;
            int length = it.first.second;
            int frequency = it.second;

            if(frequency >=3 && length > result){
                result = length;
            }
        }

        return result;
        
    }
};