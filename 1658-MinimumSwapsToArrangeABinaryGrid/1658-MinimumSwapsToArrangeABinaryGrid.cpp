// Last updated: 02/05/2026, 22:39:17
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        
        int n = grid.size();

        vector<int> endZeroes(n, 0);
        // to store consecutive no of zeroes in each row from end

        for(int row = 0; row < n; row++){

            int col = n - 1; // start from end

            int consecutiveZeroesCount = 0;

            while(col >= 0 && grid[row][col] == 0){

                consecutiveZeroesCount++;
                col--;
            }

            endZeroes[row] = consecutiveZeroesCount;

        }

        int totalSwaps = 0;

        for(int row = 0; row < n; row++){

            int need = n - row - 1;

            int col = row;

            while(col < n && endZeroes[col] < need){
                col++;
            }

            if(col == n) return -1;

            totalSwaps += col - row;

            while(col > row){

                swap(endZeroes[col], endZeroes[col -1]);
                col--;
            }
        }

        return totalSwaps;
    }
};