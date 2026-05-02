// Last updated: 02/05/2026, 22:33:23
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();       

        int topmost_one = m;
        int bottommost_one = 0;

        int leftmost_one = n;
        int rightmost_one = 0;

        for(size_t row = 0; row < m; row++){

            for(size_t col = 0; col < n; col++){

                if(grid[row][col] == 1){

                    topmost_one = min(topmost_one, (int)row);
                    bottommost_one = max(bottommost_one, (int)row);\

                    leftmost_one = min(leftmost_one, (int)col);
                    rightmost_one = max(rightmost_one, (int)col);
                }
            }
        }


        int length_of_rectangle = bottommost_one - topmost_one + 1;
        int breadth_of_rectangle = rightmost_one - leftmost_one + 1;

        int area_of_rectangle_covered_by_ones = (length_of_rectangle) * (breadth_of_rectangle);

        return area_of_rectangle_covered_by_ones;
    }
};