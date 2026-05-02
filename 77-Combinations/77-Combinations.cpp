// Last updated: 02/05/2026, 22:48:09
class Solution {
public:
    int count = 0;
    void solve(int i, int n, int k, int count, vector<int>& combination, vector<vector<int>>& result){

        //base case
        if(count == k){
            result.push_back(combination);
            return;
        }
        if(i > n) return;


        //take the current number
        combination.push_back(i);
        count++;
        solve(i+1, n, k, count, combination, result);

        //backtrack
        combination.pop_back();
        count--;

        //skip the current number
        solve(i+1, n, k, count, combination, result);

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        solve(1, n, k, 0, combination, result);
        return result;
    }
};