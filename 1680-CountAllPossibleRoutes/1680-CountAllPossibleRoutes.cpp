// Last updated: 02/05/2026, 22:39:11
class Solution {
public:
    int solve(vector<int>& locations, int start, int finish, int fuel, vector<vector<int>>& dp){

        int mod = 1e9 + 7; // to handle large values of possibleRoutes
        int n = locations.size();

        //base case
        //if fuel is finished and finish is not reached
        if(fuel < 0){
            return 0;
        }

        // if the subproblem is already solved
        if(dp[start][fuel] != -1){
            return dp[start][fuel];
        }

        int possibleRoutes = (start == finish) ? 1 : 0;

        // travelling to other locations from start        
        for(int idx = 0; idx < n; idx++){

            //skip the same location
            if(idx == start){
                continue;
            }

            //travel to other location if you have enough fuel
            int cost = abs(locations[idx] - locations[start]);
            if(cost <= fuel){
                possibleRoutes = (possibleRoutes + solve(locations, idx, finish, fuel - cost, dp)) % mod;
            }
            
        }

        return dp[start][fuel] = possibleRoutes % mod;
    }

    int solveTab(vector<int>& locations, int start, int finish, int fuel){

        int mod = 1e9 + 7; // to handle large values of possibleRoutes
        int n = locations.size(); // total no of locations

        vector<vector<int>> dp(n, vector<int>(fuel + 1 , 0));
        //dp[idx][fuel] = possible no of routes to idx with given fuel

        //if already reached finish with any amount of fuel set it to 1 possible route
        for(int f = 0; f <= fuel; f++){
            dp[finish][f] = 1;
        }

        for(int f = 0; f <= fuel; f++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){

                    //skip the same location
                    if(i == j){
                        continue;
                    }

                    //travel to other location if you have enough fuel
                    int cost = abs(locations[j] - locations[i]);
                    if(cost <= f){
                        dp[i][f] = (dp[i][f] + dp[j][f - cost]) % mod;
                    }
                }
            }
        }

        return dp[start][fuel];
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();

        // vector<vector<int>> dp(n, vector<int>(fuel + 1, -1));
        // return solve(locations, start, finish, fuel, dp);

        return solveTab(locations, start, finish, fuel);
        
    }
};