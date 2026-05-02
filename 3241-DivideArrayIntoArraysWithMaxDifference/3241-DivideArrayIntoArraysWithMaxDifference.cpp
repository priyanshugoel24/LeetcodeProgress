// Last updated: 02/05/2026, 22:34:05
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;

        while(i < n - 2){

            // check every 3 window size
            if(nums[i + 2] - nums[i] > k){
                return {};
            }

            result.push_back({nums[i], nums[i + 1], nums[i + 2]});

            i = i + 3;
        }

        return result;

    }
};