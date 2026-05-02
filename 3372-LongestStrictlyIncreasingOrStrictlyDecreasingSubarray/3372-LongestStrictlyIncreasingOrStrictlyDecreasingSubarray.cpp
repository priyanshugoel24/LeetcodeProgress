// Last updated: 02/05/2026, 22:33:44
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int n = nums.size();
        int maxLen = 1, inc = 1, dec = 1;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]) inc++, dec = 1;
            else if(nums[i] < nums[i-1]) dec++, inc = 1;
            else inc = dec = 1;
            maxLen = max(maxLen, max(inc, dec));
        }

        return maxLen;
      
        
    }
};