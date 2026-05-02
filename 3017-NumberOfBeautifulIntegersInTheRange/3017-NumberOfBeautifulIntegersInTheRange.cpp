// Last updated: 02/05/2026, 22:34:32
class Solution {
public:
    int dp[10][2][6][6][20][2];

    int solve(int idx, bool tight, int oddCount, int evenCount, int remainder, bool validNum, int &k, string& s){

        //base case : index out of bound
        if(idx >= s.length()){
            return (oddCount == evenCount) && (remainder == 0);
        }

        //base case : pruning unnecessary branches
        if((oddCount > 5) || (evenCount > 5)){
            return 0;
        }

        //if subproblem is already solved
        if(dp[idx][tight][oddCount][evenCount][remainder][validNum] != -1){
            return dp[idx][tight][oddCount][evenCount][remainder][validNum];
        }

        int ans = 0;

        //calculate limit for current index
        int limit = tight ? s[idx] - '0' : 9;

        //loop from 0 to limit
        for(int d  = 0; d <= limit; d++){
            int newTight = tight & (d == limit);

            //handle leading zeroes case
            if(validNum == false && d == 0){
                ans += solve(idx+1, newTight, oddCount, evenCount, remainder, false, k, s);

            }else if(d % 2 == 0){
                ans += solve(idx + 1, newTight, oddCount, evenCount + 1, (remainder * 10 + d) % k, true, k, s);
            }else{
                ans += solve(idx + 1, newTight, oddCount + 1, evenCount, (remainder * 10 + d) % k, true, k, s);
            }

        }

        return dp[idx][tight][oddCount][evenCount][remainder][validNum] = ans;


         
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        
       //no of beautiful integes from 0 to low - 1;
       string lower = to_string(low -1);
       memset(dp, -1, sizeof(dp));
       long count1 = solve(0, 1, 0, 0, 0, 0, k, lower);

       //no of beautiful integers from 0 to high
       string higher = to_string(high);
       memset(dp, -1, sizeof(dp));
       long count2 = solve(0, 1, 0, 0, 0, 0, k, higher);

       return count2 - count1;
    }
};