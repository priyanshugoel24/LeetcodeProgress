// Last updated: 02/05/2026, 22:32:46
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        
        int n = nums.size();

        int subarrays = 0;

        for(int i = 0; i < n - 2; i++){

            int first = nums[i];
            int second = nums[i + 1];
            int third = nums[i + 2];

            if(first + third == ((double)second / 2)){
                subarrays += 1;
            }

        }

        return subarrays;
    }
};