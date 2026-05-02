// Last updated: 02/05/2026, 22:37:39
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int n = nums.size();

       int max_difference = -1;
       int previous_min_element = nums[0];

       for(int i = 1; i < n; i++){

        if(nums[i] <= previous_min_element){
            previous_min_element = nums[i];
        }else{

            int curr_difference = nums[i] - previous_min_element;
            max_difference = max(max_difference, curr_difference);
        }
       }


       return max_difference;

    }
};