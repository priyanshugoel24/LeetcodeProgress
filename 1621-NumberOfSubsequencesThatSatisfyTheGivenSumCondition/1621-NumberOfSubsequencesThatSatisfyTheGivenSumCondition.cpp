// Last updated: 02/05/2026, 22:39:25
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(begin(nums), end(nums));
        int mod = 1e9 + 7;

        int valid_subsequences = 0;

        vector<int> power(n, 1);
        for(int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % mod;
        }


        int l = 0, r = n - 1;

        while(l <= r){

            if(nums[l] + nums[r] > target){
                r--;
            }else{

                valid_subsequences = (valid_subsequences + power[r - l]) % mod;
                l++;
            }
        }

        return valid_subsequences;

        
    }
};