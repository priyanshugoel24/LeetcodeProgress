// Last updated: 02/05/2026, 22:45:44
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i<n-1; i++){
            if(nums[i] == 0 && nums[i+1] == 0 ){
                
                for(int j = i+2; j<n; j++){
                    if(nums[j] != 0){
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }

            if(nums[i] == 0 && nums[i+1] != 0){
                swap(nums[i], nums[i+1]);
            }
        }


        
    }
};