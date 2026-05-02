// Last updated: 02/05/2026, 22:35:43
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_set<int> s;
        int l = 0;
        long long currSum = 0, maxSum = 0;

        for(int r = 0; r < n; r++){
            if(s.find(nums[r]) == s.end()){
                currSum += nums[r];
                s.insert(nums[r]);

                if(r-l+1 == k){
                maxSum = max(maxSum, currSum);
                currSum -= nums[l];
                s.erase(nums[l]);
                l++;
                }
            } else{
                while(nums[l] != nums[r]){
                    currSum -= nums[l];
                    s.erase(nums[l]);
                    l++;
                }
                l++;
            }

            
        }

        return maxSum;

        
    }
};