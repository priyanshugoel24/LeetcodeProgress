// Last updated: 02/05/2026, 22:44:47
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int lenOfArray = nums.size();

        vector<int> duplicates;

        for(int idx = 0; idx < lenOfArray; idx++){

            int currNum = abs(nums[idx]);

            int idxOfNum = currNum - 1;

            if(nums[idxOfNum] < 0){

                duplicates.push_back(currNum);
            }else{

                nums[idxOfNum] = -nums[idxOfNum];
            }
        }

        return duplicates;

    }
};