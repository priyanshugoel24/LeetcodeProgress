// Last updated: 02/05/2026, 22:40:41
class Solution {
public:
    int f(vector<int>& nums, int goal){

        if(goal < 0) return 0;
        int n = nums.size(), l = 0, r= 0;
        int currSum = 0, ans = 0;

        while(r < n){

            currSum += nums[r]%2;

            while(currSum > goal){

                currSum -= nums[l]%2;
                l++;
            } 

            ans += r-l+1;
            r++;           
            
        }

        return ans;
        
    }
    int numberOfSubarrays(vector<int>& nums, int k) {

        return f(nums, k) - f(nums, k-1);
        
    }
};