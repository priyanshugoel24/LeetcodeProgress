// Last updated: 02/05/2026, 22:45:28
class Solution {
public:
    bool isPowerOfThree(int n) {
        
        int exp = log(INT_MAX) / log(3);

        int max_num = pow(3, exp);

        return n > 0 && max_num % n == 0;

    }
};