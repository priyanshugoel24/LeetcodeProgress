// Last updated: 02/05/2026, 22:45:51
class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        int total = ((n+1)*n)/2;

        for(int i = 0; i<n; i++){
            total -= nums[i];
        }

        return total;

        
    }
};