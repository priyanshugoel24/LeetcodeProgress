// Last updated: 02/05/2026, 22:44:20
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int n = nums.size();

        int prefSum = 0, ans = 0;

        for(int i = 0; i<n; i++){

            prefSum += nums[i];
            int rem = prefSum - k;
            ans += mpp[rem];
            mpp[prefSum] += 1;
        }

        return ans;
        
    }
};