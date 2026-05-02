// Last updated: 02/05/2026, 22:48:45
class Solution {
public:
    void f(int ind, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combination){
        int n = candidates.size();
        
        //base case
        if(ind == n){
            if(target == 0) ans.push_back(combination);
            return;
        }

        //take
        if(candidates[ind] <= target){
            combination.push_back(candidates[ind]);
            f(ind, candidates, target-candidates[ind], ans, combination);
            combination.pop_back();
        }

        // notTake
        f(ind+1, candidates, target, ans, combination);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> combination;
        f(0,candidates, target, ans, combination);

        return ans;
        
    }
};