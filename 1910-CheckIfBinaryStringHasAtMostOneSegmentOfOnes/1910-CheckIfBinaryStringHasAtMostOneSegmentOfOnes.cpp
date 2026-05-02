// Last updated: 02/05/2026, 22:38:25
class Solution {
public:
    bool checkOnesSegment(string s) {
        
        bool is01SequencePresent = false;

        for(int i = 0; i < s.size() - 1; i++){

            if(s[i] == '0' && s[i + 1] == '1'){
                is01SequencePresent = true;
                break;
            }
        }

        return !is01SequencePresent;
    }
};