// Last updated: 02/05/2026, 22:34:02
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        
        int max_diagonal_length = 0;
        int area_of_max_diagonal_rectangle = 0;

        for(auto& dimension : dimensions){

            int length = dimension[0], breadth = dimension[1];

            int curr_diagonal_length = (length * length) + (breadth * breadth);
            int curr_area = (length * breadth);

            if(curr_diagonal_length > max_diagonal_length){
                max_diagonal_length = curr_diagonal_length;
                area_of_max_diagonal_rectangle = curr_area;
            }else if(curr_diagonal_length == max_diagonal_length){

                area_of_max_diagonal_rectangle = max(area_of_max_diagonal_rectangle, curr_area);
            }
        }

        return area_of_max_diagonal_rectangle;
    }
};