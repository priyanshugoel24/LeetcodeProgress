// Last updated: 02/05/2026, 22:46:49
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();

        int element = -1;

        int counter = 0;

        for(int i = 0; i < n; i++){

            if(counter == 0){
                counter = 1;
                element = nums[i];
                continue;
            }

            if(nums[i] == element){
                counter++;
            }else{
                counter--;
            }
        }

       return element;
        
    }
};