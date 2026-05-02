// Last updated: 02/05/2026, 22:34:25
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        long long result = 0;

        long long maxDiff = 0, maxi = 0;

        for(int k = 0; k < n; k++){
            result= max(result, maxDiff * nums[k]);
            maxDiff = max(maxDiff, maxi - nums[k]);
            maxi = max(maxi, (long long)nums[k]);
        }

        return result;
    }
};