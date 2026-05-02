// Last updated: 02/05/2026, 22:37:44
class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();

        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> arr(st.begin(), st.end());
        sort(arr.begin(), arr.end());

        int max_window = 0;
        int j = 0;

        for (int i = 0; i < arr.size(); i++) {
            while (arr[i] - arr[j] >= n) {
                j++;
            }

            max_window = max(max_window, i - j + 1);
        }

        return n - max_window;
    }
};
