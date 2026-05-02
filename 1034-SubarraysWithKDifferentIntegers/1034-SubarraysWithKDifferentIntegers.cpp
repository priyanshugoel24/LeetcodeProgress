// Last updated: 02/05/2026, 22:41:59
class Solution {
public:
    int f(vector<int>& nums, int k){

        int l = 0, r = 0, cnt = 0, n = nums.size();
        unordered_map<int,int> hash;

        while(r < n){

            hash[nums[r]]++;

            while(hash.size() > k){
                hash[nums[l]]--;
                if(hash[nums[l]] == 0) hash.erase(nums[l]);
                l++;
            }

            cnt += r-l+1;
            r++;
        }

        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return f(nums, k) - f(nums, k-1);
        
    }
};