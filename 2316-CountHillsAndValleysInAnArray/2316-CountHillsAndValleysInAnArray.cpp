// Last updated: 02/05/2026, 22:36:49
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        int n = nums.size();

        int hillsAndValleys = 0;

        for(int i = 1; i < n - 1; i++){

            if(nums[i] == nums[i - 1]){
                continue;
            }

            int curr_num = nums[i];

            int j = i - 1, k = i + 1;

            while(j >= 0 && nums[j] == curr_num){
                j--;
            }

            while(k < n && nums[k] == curr_num){
                k++;
            }

            if(j >= 0 && k < n){
                bool valleyCheck = (nums[j] > curr_num && nums[k] > curr_num);
                bool hillCheck = (nums[j] < curr_num && nums[k] < curr_num);

                if(valleyCheck || hillCheck){
                    hillsAndValleys++;
                }
            }
            
            
        }

        return hillsAndValleys;
    }
};