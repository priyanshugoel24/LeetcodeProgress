// Last updated: 02/05/2026, 22:32:53
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        
        int n = fruits.size();

        // collect fruits from child 1
        int fruitsFromChild1 = 0;

        for(int i = 0; i < n; i++){

            fruitsFromChild1 += fruits[i][i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // nullify the collections of cells in which child 2 and child 3 cannot reach because of movement constraints

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                if(i + j >= n- 1){
                    dp[i][j] = fruits[i][j];
                }
            }
        }

        // collect fruits from child 2
        int fruitsFromChild2 = 0;

        for(int i = 1; i < n; i++){
            for(int j = i + 1; j < n; j++){

                int up = dp[i - 1][j];
                int diagonal_left_up = dp[i - 1][j - 1];
                int diagonal_right_up = (j + 1 < n) ? dp[i - 1][j + 1] : 0;
                
                dp[i][j] += max({up, diagonal_left_up, diagonal_right_up});
            }
        }

        fruitsFromChild2 = dp[n - 2][n - 1];


        // collect fruits from child 3
        int fruitsFromChild3 = 0;

        for(int j = 1 ; j < n; j++){
            for(int i = j + 1; i < n; i++){

                int left = dp[i][j - 1];
                int diagonal_left_up = dp[i - 1][j - 1];
                int diagonal_bottom_up = (i + 1 < n) ? dp[i + 1][j - 1] : 0;

                dp[i][j] += max({left, diagonal_left_up, diagonal_bottom_up});
            }
        }

        fruitsFromChild3 = dp[n - 1][n - 2];

        // calculate the max fruits collected by all children
        int max_fruits_collected = fruitsFromChild1 + fruitsFromChild2 + fruitsFromChild3;


        // return the max fruits obtained at the destination
        return max_fruits_collected;
    }
};