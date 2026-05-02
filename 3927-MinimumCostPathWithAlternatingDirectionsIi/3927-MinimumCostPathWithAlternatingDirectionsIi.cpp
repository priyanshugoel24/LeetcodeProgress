// Last updated: 02/05/2026, 22:32:18
class Solution {
public:
    long long solve(int x, int y, int m, int n, int currSeconds, vector<vector<int>>& waitCost, vector<vector<vector<long long>>>& dp){

        //base case : if reached the bottom right corner cell
        if(x == m - 1 && y == n -1 ){
            return 0;
        }

        // base case : out of boundary
        if(x == m || y == n){
            return 1e18;
        }

        if(dp[x][y][currSeconds % 2] != -1){
            return dp[x][y][currSeconds % 2];
        }

        long long min_path_cost = LLONG_MAX;

        if(currSeconds % 2 == 0){
            min_path_cost = min(min_path_cost, waitCost[x][y] + solve(x, y, m, n, currSeconds + 1, waitCost, dp));
        }else{

            long long down_cost = (long long)((x + 2)* (y + 1)) + solve(x + 1, y, m, n, currSeconds + 1, waitCost, dp);
            long long right_cost = (long long)((x + 1) * (y + 2)) + solve(x, y + 1, m, n, currSeconds + 1, waitCost, dp);

            min_path_cost = min(right_cost, down_cost);
        }

        return dp[x][y][currSeconds % 2] = min_path_cost;
    }
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, -1)));
        return 1 + solve(0, 0, m, n, 1, waitCost, dp);
    }
};