// Last updated: 02/05/2026, 22:47:57
class Solution {
private:

public:
    void f(int ind, vector<int>& nums, vector<int> &subset, set<vector<int>>& ans){
        if(ind == nums.size()){
            
            ans.insert(subset);            
            return;
        }

        //take
        subset.push_back(nums[ind]);
        f(ind+1, nums, subset, ans);
        subset.pop_back();

        //notTake

        f(ind+1, nums, subset, ans);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> v;
        set<vector<int>> ans;
        vector<int> subset;

        sort(nums.begin(), nums.end());

        f(0, nums, subset, ans);
        
        for(auto& i : ans){
            v.push_back(i);
        }

        return v;
        
    }
};