// Last updated: 02/05/2026, 22:37:57
class Solution {
public:
    // fast exponentiation
    int findPower(long long a, long long b){
        int mod = 1e9 + 7;
        //base case
        if(b == 0){
            return 1;
        }

        long long half = findPower(a , b/2);
        long long result = (half * half) % mod;
        
        if(b % 2 == 1){
            result = (result * a ) % mod;
        }

        return result;

    }
    int countGoodNumbers(long long n) {
        int mod = 1e9 + 7;

        // even indices -> (n + 1) / 2 have 5 possibilities and odd indices -> n/2 have 4 possibilities
        return (long long)findPower(5, ( n + 1) / 2) * findPower(4, n / 2) % mod;
    }
};