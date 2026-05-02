// Last updated: 02/05/2026, 22:34:51
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        return accumulate(derived.begin(), derived.end(), 0, bit_xor<>()) == 0;
        
    }
};