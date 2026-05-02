// Last updated: 02/05/2026, 22:34:12
class Solution {
public:
    long long combinationCount(int sum){

        if(sum < 0) return 0;

        return 1LL * (sum + 2) * (sum + 1) / 2;
    }
    long long distributeCandies(int n, int limit) {
        
        return combinationCount(n) - 3 * combinationCount(n - (limit + 1)) + 3 * combinationCount(n - 2 * (limit + 1)) - combinationCount(n - 3 * (limit + 1));
        
    }
};