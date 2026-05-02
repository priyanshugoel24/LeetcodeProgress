// Last updated: 02/05/2026, 22:35:09
class Solution {
public:
    void solve(int idx, vector<int>& nums, unordered_map<int,int>& mp, int k, int& result){

        //base case
        if(idx >= nums.size()){
            result++;
            return;
        }

        //take
        if(!mp[nums[idx] - k] && !mp[nums[idx] + k]){

            mp[nums[idx]]++;
            solve(idx+1, nums, mp, k, result);
            mp[nums[idx]]--;
        }

        // notTake
        solve(idx+1, nums, mp, k, result);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int,int> mp;

        solve(0, nums, mp, k, result);

        return result-1;
    }
};