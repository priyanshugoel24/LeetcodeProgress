// Last updated: 02/05/2026, 22:48:44
class Solution {
private:
    vector<vector<int>> ans;

public:
    void f(int ind, vector<int>& candidates, int target,
           vector<int>& combination) {

        int n = candidates.size();

        if (target == 0) {
            ans.push_back(combination);
            return;
        }

        if (ind == n || target < candidates[ind])
            return;

        // take
        int temp = candidates[ind];

        combination.push_back(candidates[ind]);
        f(ind + 1, candidates, target - candidates[ind], combination);
        combination.pop_back();

        int i = 1;
        while (ind + i < n && candidates[ind + i] == temp){i++;}
            

        // notTake
        f(ind + i, candidates, target, combination);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> combination;
        f(0, candidates, target, combination);

        return ans;
    }
};