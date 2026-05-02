// Last updated: 02/05/2026, 22:45:00
class Solution {
public:
    bool isPossible(int mid, vector<int>& nums, int k){

        int n = nums.size();

        int partitions = 1;
        int currSum = 0;

        for(int i = 0; i < n; i++){

            if(currSum + nums[i] > mid){
                partitions++;
                currSum = nums[i];
            }else{
                currSum += nums[i];
            }
        }

        return (partitions <= k);
    }
    int splitArray(vector<int>& nums, int k) {

       

        int low = *max_element(nums.begin(), nums.end()), high = accumulate(nums.begin(), nums.end(), 0);

        int minSubarraySum = low;

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(isPossible(mid, nums, k)){
                minSubarraySum = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return minSubarraySum;
    }
};