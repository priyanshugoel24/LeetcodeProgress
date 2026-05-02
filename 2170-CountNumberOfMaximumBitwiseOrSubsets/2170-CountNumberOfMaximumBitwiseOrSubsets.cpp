// Last updated: 02/05/2026, 22:37:29
class Solution {
public:
    void f(vector<int>& nums, int index, int currOr, int maxOr, int &count){

        if(currOr == maxOr) count++;

        for(int i = index; i<nums.size(); i++){
            f(nums, i+1, currOr|nums[i], maxOr, count);

        }
    }
    int countMaxOrSubsets(vector<int>& nums) {

        int maxOr = 0;

        for(int i = 0; i<nums.size(); i++){
            maxOr |= nums[i];
        }

        int count = 0; 
        f(nums, 0, 0, maxOr, count);
        return count;
        
    }
};