// Last updated: 02/05/2026, 22:49:13
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0, right = height.size() - 1;

        int max_container_area = 0;

        while(left <= right){

            int curr_area = min(height[right], height[left]) * (right - left);

            max_container_area = max(max_container_area, curr_area);

            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }

        return max_container_area;
    }
};