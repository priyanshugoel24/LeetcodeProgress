// Last updated: 02/05/2026, 22:48:36
class Solution {
public:
    void solve(unordered_map<int,int>& mp, int n, vector<int>& temp, vector<vector<int>>& result){

        if(temp.size() == n){
            result.push_back(temp);
            return;
        }

        for(auto& [num, count] : mp){
            if(count == 0) continue;

            temp.push_back(num);
            mp[num]--;

            solve(mp, n, temp, result);

            temp.pop_back();
            mp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<vector<int>> result;

        for(int &num : nums){
            mp[num]++;
        }

        vector<int> temp;
        solve(mp, n,temp, result);

        return result;
    }
};