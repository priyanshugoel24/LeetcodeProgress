// Last updated: 02/05/2026, 22:38:30
class Solution {
public:
    bool checkPowersOfThree(int n) {
        return n%3 == 2 ? 0 : (n > 3 ? checkPowersOfThree(n/3) : 1);
    }
};