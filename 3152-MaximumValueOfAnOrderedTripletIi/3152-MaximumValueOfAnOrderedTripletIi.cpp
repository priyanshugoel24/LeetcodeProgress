// Last updated: 02/05/2026, 22:34:26
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxLeft(n, 0); // stores max element to the left of index i
        vector<int> maxRight(n, 0); // stores max element to the right of index i


        //filling maxLeft array
        int leftMax = nums[0];
        for(int i = 0; i < n ; i++){
            maxLeft[i] = leftMax;
            leftMax = max(leftMax, nums[i]);

        }

        // filling maxRight array
        int rightMax = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            maxRight[i] = rightMax;
            rightMax = max(rightMax, nums[i]);
        }

        long long maxVal = 0;

        for(int i = 1; i < n-1; i++){
             if (maxLeft[i] > nums[i] && maxRight[i] > 0) { // Ensuring valid triplet
                long long currVal = (long long)(maxLeft[i] - nums[i]) * maxRight[i];
                maxVal = max(maxVal, currVal);
            }
        }

        return maxVal;


    }
};