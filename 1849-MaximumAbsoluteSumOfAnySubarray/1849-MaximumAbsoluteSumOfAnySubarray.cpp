// Last updated: 02/05/2026, 22:38:40
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0, minSum = 0, maxSum = 0;
        for(int num : nums){
            sum += num;
            if(sum > maxSum) maxSum = sum;
            if(sum < minSum) minSum = sum;
        }

        return abs(maxSum - minSum);
    }
};