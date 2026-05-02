// Last updated: 02/05/2026, 22:48:38
class Solution {
public:
    void solve(vector<int>& nums, int n, int idx, vector<int>& permutation,vector<int>& freq,vector<vector<int>>& result){

        if(permutation.size() == n){
            result.push_back(permutation);
            return;
        }

        for(int i = 0; i<n; i++){
            if(!freq[i]){
                permutation.push_back(nums[i]);
                freq[i] = 1;
                solve(nums, n, (idx+1)%n, permutation, freq, result);
                freq[i] = 0;
                permutation.pop_back();
            }
           

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> result;
        vector<int> freq(n, 0);

        vector<int> permutation;
        
        solve(nums, n, 0, permutation,freq, result);

        return result;
        
    }
};