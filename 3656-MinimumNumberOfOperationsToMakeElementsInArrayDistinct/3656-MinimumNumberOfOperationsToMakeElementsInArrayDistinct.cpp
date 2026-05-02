// Last updated: 02/05/2026, 22:32:51
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> last;

        int res = 0;

        for(int i = 0; i < nums.size(); i++){
            
            if(last.count(nums[i]) && last[nums[i]] >= 3 * res){
                res = (last[nums[i]] + 1 + 2) / 3;
            }

            last[nums[i]] = i;
        }

        return res;


    }
};