// Last updated: 02/05/2026, 22:43:04
class Solution {
public:
    double solve(double a, double b, vector<vector<double>>& dp){

        //base case
       if(a <= 0 && b <= 0){
        return 0.5000;
       }
       if(a <= 0){
        return 1.0000;
       }
       if(b <= 0){
        return 0.0000;
       }

       //if the subproblem is already solved
       if(dp[a][b] != -1){
        return dp[a][b];
       }

        double result = 0.00;

        //four possible operations
        result += 0.25 * solve( a - 4, b, dp);
        result += 0.25 * solve( a - 3, b - 1, dp);
        result += 0.25 * solve(a - 2, b - 2, dp);
        result += 0.25 * solve(a - 1, b - 3, dp);

        return dp[a][b] = result;
    }

    double solveTab(int n){

        //scale down input for very large n 
        if( n > 5000) return 1.0;
        double N = ceil(n / 25.0);

        vector<vector<double>> dp(N+1, vector<double>(N+1, 0));

        //base cases
        dp[0][0] = 0.5000;

        for(double b = 1; b <= N; b++){
            dp[0][b] = 1.0000;
        }

        for(int a = 1; a <= N; a++){
            
            for(int b = 1; b <= N; b++){

                double result = 0.0;

                //four possible operations
                result += 0.25 * dp[max(0, a-4)][b];
                result += 0.25 * dp[max(0, a-3)][b-1];
                result += 0.25 * dp[max(0, a-2)][max(0, b-2)];
                result += 0.25 * dp[a-1][max(0, b-3)];

                dp[a][b] = result;
                
            }
        }

        return dp[N][N];
    }
    double soupServings(int n) {
        
        //scale down input for very large n 
        // if( n > 5000) return 1.0;
        // double N = ceil(n / 25.0);

        // vector<vector<double>> dp(N+1, vector<double>(N+1, -1));

        // return solve(N, N, dp);

        return solveTab(n);
    }
};