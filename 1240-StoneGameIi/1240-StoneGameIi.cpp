// Last updated: 02/05/2026, 22:41:20
class Solution {
public:
    int solve(vector<int>& piles, int person, int i, int M, vector<vector<vector<int>>>& dp){

        int n = piles.size();

        //base case
        if(i >= n){
            return 0;
        }

        // if the subproblem is already solved
        if(dp[person][i][M] != -1){
            return dp[person][i][M];
        }

        //result is initially very small value for alice and very large value for bob
        int result = (person == 1) ? -1 : INT_MAX;

        int stones = 0;

        for(int x = 1 ; x <= min(2 * M, n - i); x++){
            stones += piles[i + x - 1];

            //alice's turn
            if(person == 1){
                result = max(result, stones + solve(piles, 0, i+x, max(M, x), dp));
            }
            //bob's turn
            else{
                result = min(result, solve(piles, 1, i + x, max(M, x), dp));
            }
        }

        return dp[person][i][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        return solve(piles, 1, 0, 1, dp); // 1 -> alice, 0-> bob
    }
};