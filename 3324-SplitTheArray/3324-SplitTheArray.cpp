// Last updated: 02/05/2026, 22:33:51
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        
        unordered_map<int, int> freq;

        for(int& num : nums){
            freq[num]++;
        }

        for(auto& it : freq){

            int count = it.second;

            if(count > 2) return false;
        }

        return true;
    }
};