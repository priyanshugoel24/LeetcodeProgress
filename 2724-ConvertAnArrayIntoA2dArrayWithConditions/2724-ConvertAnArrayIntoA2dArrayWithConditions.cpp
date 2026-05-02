// Last updated: 02/05/2026, 22:34:59
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        int n = nums.size();

        unordered_map<int, int> freq;
        vector<vector<int>> result;

        for(int i = 0; i < n; i++){

            int occurence_no = freq[nums[i]];

            // add a new row
            if(occurence_no == result.size()){
                result.push_back({});
            }

            result[occurence_no].push_back(nums[i]);
            freq[nums[i]]++;
        }

        return result;

        
    }
};