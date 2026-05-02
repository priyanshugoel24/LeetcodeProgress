// Last updated: 02/05/2026, 22:38:08
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        int result = 0;

        for(int &num : nums){
            result |= num;
        }

        return result << (n-1);
    }
};