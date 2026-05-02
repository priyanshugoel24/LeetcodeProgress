// Last updated: 02/05/2026, 22:40:19
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int count = 0;
        int windowSum = 0;
        int target = k * threshold;

        // initialize first window
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }
        if (windowSum >= target) count++;

        // slide the window
        for (int i = k; i < n; i++) {
            windowSum += arr[i] - arr[i - k];
            if (windowSum >= target) count++;
        }

        return count;
    }
};
