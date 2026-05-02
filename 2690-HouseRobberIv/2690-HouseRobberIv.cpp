// Last updated: 02/05/2026, 22:35:15
class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int k) {
        int house = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] <= mid) {
                house++;
                i++;
            }
        }

        return house >= k;
    }
    int minCapability(vector<int>& nums, int k) {

        int n = nums.size();

        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isPossible(nums, mid, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};