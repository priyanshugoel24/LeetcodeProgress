// Last updated: 02/05/2026, 22:36:14
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        long long result = 0;
        for(int i = 0; i<n; i++){
            nums[i] = nums[i]-i;
        }

        unordered_map<int, int> mp;
        mp[nums[0]] = 1;

        for(int j = 1; j< n ; j++){
            int countofNumsIdx = mp[nums[j]];

            int totalNumsbeforeIdx = j;

            int badPairs = totalNumsbeforeIdx - countofNumsIdx;

            result += badPairs;

            mp[nums[j]]++;


        }


        return result;
        
    }
};