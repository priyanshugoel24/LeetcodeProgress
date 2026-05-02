// Last updated: 02/05/2026, 22:48:07
class Solution {
public:
    void solve(vector<int>&nums, int idx, int n, vector<int>& subset, vector<vector<int>>& ans){

        //base case
        if(idx >= n){
            ans.push_back(subset);
            return;
        }

        //take
        subset.push_back(nums[idx]);
        solve(nums, idx+1, n, subset, ans);

        //notTake
        subset.pop_back();
        solve(nums, idx+1, n, subset, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> subset;

        solve(nums, 0, n, subset, ans);

        return ans;
    }
};