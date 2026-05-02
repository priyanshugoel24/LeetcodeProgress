// Last updated: 02/05/2026, 22:36:56
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> rearrangedArray(n);

        int posIndex = 0, negIndex = 1;

        for(int index = 0; index < n; index++){

            if(nums[index] < 0){
                rearrangedArray[negIndex] = nums[index];
                negIndex += 2;
            }else{
                rearrangedArray[posIndex] = nums[index];
                posIndex += 2;
            }
        }

        return rearrangedArray;
    }
};