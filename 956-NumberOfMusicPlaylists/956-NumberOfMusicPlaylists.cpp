// Last updated: 02/05/2026, 22:42:19
class Solution {
public:
    int solve(int count_song, int count_unique, int n, int goal, int k, vector<vector<int>>& dp){
        int mod = 1e9 + 7;

        //base case : goal no of songs are played
        if(count_song == goal){

            //if no of unique songs is equal to n, it is a valid playlist
            if(count_unique == n){
                return 1;
            }

            //else it is invalid playlists
            return 0;
        }

        //if subproblem is already solved
        if(dp[count_song][count_unique] != -1){
            return dp[count_song][count_unique];
        }

        int playlists = 0; // no of playlists possible

        //option1 : play a unique song
        if(count_unique < n){
            //at this point we can play a unique song which will be total - no of unique songs already played
            playlists = (playlists + (long long)(n - count_unique) * solve(count_song + 1, count_unique + 1, n, goal, k, dp)) % mod;
        }

        //option2 : play a repeated song
        if(count_unique > k){
            //at this point we want to play a repeated song which for all places will be equal to no of unique songs played til now - k
            playlists = (playlists + (long long)(count_unique - k) * solve(count_song + 1, count_unique, n, goal, k, dp)) % mod;
        }

        //memoize the result
        return dp[count_song][count_unique] = playlists % mod;

    }

    int solveTab(int n, int goal, int k){
        int mod = 1e9 + 7;
        vector<vector<int>> dp(goal + 1, vector<int>(n + 1, 0)); //tabulation matrix
        //dp[goal][n] gives no of playlists for goal songs with n unique songs

        dp[0][0] = 1;

        for(int count_song = 1; count_song <= goal; count_song++){
            for(int count_unique = 1; count_unique <= n; count_unique++){

                int playlists = 0;
                //option1 : play a unique song
               
                //at this point we can play a unique song which will be total - no of unique songs already played
                playlists = (playlists + (long long)(n - (count_unique - 1)) * dp[count_song -1][count_unique -1]) % mod;
            

                //option2 : play a repeated song
                if(count_unique > k){
                    //at this point we want to play a repeated song which for all places will be equal to no of unique songs played til now - k
                    playlists = (playlists + (long long)(count_unique - k) * dp[count_song -1][count_unique]) % mod;
                }

                dp[count_song][count_unique] = playlists % mod;
                    
            }
        }

        return dp[goal][n];

    }
    int numMusicPlaylists(int n, int goal, int k) {
        
        int count_song = 0; // no of songs played
        int count_unique = 0; // no of unique songs played

        // vector<vector<int>> dp(goal+1, vector<int>(n + 1, -1)); // memoization array

        // return solve(count_song, count_unique, n, goal, k, dp);

        return solveTab(n, goal, k);
    }
};