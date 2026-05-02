// Last updated: 02/05/2026, 22:40:30
class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int threshold){

        int n = nums.size();

        int sum = 0;

        for(int i = 0; i < n; i++){

            sum += ceil((double)nums[i] / (double)mid);
        }

        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1, high = *max_element(nums.begin(), nums.end());

        int ans = -1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(isPossible(nums, mid, threshold)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};