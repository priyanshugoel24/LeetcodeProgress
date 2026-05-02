// Last updated: 02/05/2026, 22:46:10
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n <= 0) return false;
        return !(n & (n - 1));
    }
};