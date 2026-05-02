// Last updated: 02/05/2026, 22:33:34
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {

        int n = nums.size();

        if(n < 2 ) return true;

        bool initialParity = (nums[0]%2 == 0);

        for(int i = 1 ; i<n; i++){
            if((nums[i] %2 == 0) == initialParity) return false;
            initialParity = !initialParity;
        }

        return true;
        
    }
};