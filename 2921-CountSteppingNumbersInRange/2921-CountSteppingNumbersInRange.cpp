// Last updated: 02/05/2026, 22:34:36
class Solution {
public:
    long long dp[101][2][10][2];

    long long solve(int idx, bool tight, int prev, bool validNum, string& s){

        int mod = 1e9 + 7;

        //base case : index out of bound
        if(idx == s.size()){
            
            //return 1 if we have formed a valid number
            if(validNum){
                return 1;
            }

            return 0;
        }

        //if subproblem is already solved
        if(dp[idx][tight][prev][validNum] != -1){
            return dp[idx][tight][prev][validNum];
        }

        long long ans = 0;

        //calculate limit for current index
        int limit = tight ? s[idx] - '0' : 9;

        //loop from 0 to limit
        for(int d = 0; d <= limit; d++){
            int newTight = tight & (d == limit);

            //handle leading zeroes
            if(validNum == false && d == 0){
                ans = (ans +  solve(idx + 1, newTight , prev, false, s)) % mod;
            }
            // first digit > 0
            else if(validNum == false && d > 0){
                ans = (ans + solve(idx + 1, newTight, d, true, s)) % mod;
            }
            // 2nd or further digit > 0
            else if(abs(d - prev) == 1){
                ans = (ans + solve(idx + 1, newTight, d, true, s)) % mod;
            }
        }

        return dp[idx][tight][prev][validNum] = ans;

    }
    int countSteppingNumbers(string low, string high) {
        int mod = 1e9 + 7;
        //find numbers till low
        memset(dp, -1, sizeof(dp));
        long long countNum1 = solve(0, true, 0, 0, low);

        //check for low separately
        int i = 1;
        while(i < low.size()){
            if(abs((low[i] - '0') - (low[i - 1] - '0') ) != 1){
                break;
            }
            i++;
        }

        if(i == low.size()){
            countNum1--;
        }

        //find numbers till high
        memset(dp, -1, sizeof(dp));
        long long countNum2 = solve(0, true, 0, 0, high);

        return (((countNum2 - countNum1) % mod) + mod) % mod;
    }
};