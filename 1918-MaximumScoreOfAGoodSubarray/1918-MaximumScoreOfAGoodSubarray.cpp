// Last updated: 02/05/2026, 22:38:21
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        
        int n = nums.size();
        int left = k, right = k;
        
        int minVal = nums[k];
        int maxScore = nums[k];

        while (left > 0 || right < n - 1) {

            // Expand to the side with larger value to keep minVal higher
            if (left == 0) {
                right++;
            } else if (right == n - 1) {
                left--;
            } else if (nums[left - 1] > nums[right + 1]) {
                left--;
            } else {
                right++;
            }

            minVal = min(minVal, min(nums[left], nums[right]));
            maxScore = max(maxScore, minVal * (right - left + 1));
        }

        return maxScore;
    }
};
