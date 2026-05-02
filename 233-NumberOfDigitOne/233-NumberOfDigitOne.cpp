// Last updated: 02/05/2026, 22:46:07
class Solution {
public:
    int dp[10][2][10];

    int solve(int idx, bool tight, int oneCount, string &s){

        //base case : index out of bound
        if(idx == s.size()){
            return oneCount;
        }

        //if subproblem is already solved
        if(dp[idx][tight][oneCount] != -1){
            return dp[idx][tight][oneCount];
        }

        int ans = 0;

        //calculate limit for current index
        int limit = tight ? s[idx] - '0' : 9;

        //loop from 0 to limit
        for(int d = 0; d <= limit; d++){
            int newTight = tight & ( d == limit);
            int newOneCount = oneCount + (d == 1);

            ans += solve(idx + 1, newTight, newOneCount, s);
        }

        //memoize the state
        return dp[idx][tight][oneCount] = ans;
    }
    int countDigitOne(int n) {

        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        
        return solve(0, true, 0, s);
        
    }
};