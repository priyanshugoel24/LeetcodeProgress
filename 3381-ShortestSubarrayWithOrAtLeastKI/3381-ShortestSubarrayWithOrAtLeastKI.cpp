// Last updated: 02/05/2026, 22:33:41
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {

        int n = nums.size();
        int len = INT_MAX;

        for(int i = 0; i<n; i++){
            int val = 0;

            for(int j = i; j<n; j++){
                val |= nums[j];

                if(val >= k){
                    len = min(len, j-i+1);
                }
            }
        }

        if(len == INT_MAX) return -1;
        return len;
        
    }
};