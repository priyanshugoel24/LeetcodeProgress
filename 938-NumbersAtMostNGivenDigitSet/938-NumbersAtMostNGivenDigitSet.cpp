// Last updated: 02/05/2026, 22:42:25
class Solution {
public:
    int dp[10][2][2];
    int solve(int idx, bool tight, bool validNum, vector<string>& digits, string& s){

        //base case : index out of bound
        if(idx == s.size()){

            if(validNum){
                return 1;
            }

            return 0;
        }

        //if subproblem is already solved
        if(dp[idx][tight][validNum] != -1){
            return dp[idx][tight][validNum];
        }

        int ans = 0;

        //calculate limit for current index
        int limit = tight ? s[idx] - '0' : 9;

        //handle leading zeroes
        if(validNum == false){
            ans += solve(idx + 1, false, false, digits, s);
        }

        //loop for digits array
        for(auto it : digits){

            int d = stoi(it);
            int newTight = tight & (d == limit);
            if(d > limit){ // number > s
                break;
            }

            ans += solve(idx + 1, newTight, true, digits, s);
        }

        return dp[idx][tight][validNum] = ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));

        return solve(0, true, false, digits, s);
    }
};