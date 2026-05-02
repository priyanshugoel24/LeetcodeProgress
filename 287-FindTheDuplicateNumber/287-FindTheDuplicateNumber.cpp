// Last updated: 02/05/2026, 22:45:43
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(size_t idx = 0; idx < nums.size(); idx++){

            int curr_num = nums[idx];

            int num_to_idx = abs(curr_num) - 1;


            if(nums[num_to_idx] < 0){
                return abs(curr_num);
            }else{
                nums[num_to_idx] = -nums[num_to_idx];
            }
        }

        return -1;
    }
};