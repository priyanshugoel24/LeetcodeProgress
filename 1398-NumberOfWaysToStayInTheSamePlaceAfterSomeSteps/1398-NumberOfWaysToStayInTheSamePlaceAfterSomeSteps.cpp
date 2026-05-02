// Last updated: 02/05/2026, 22:40:33
class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int MOD = 1e9 + 7;
        int maxPos = min(arrLen, steps); // never need to go beyond steps

        vector<int> prev(maxPos, 0), curr(maxPos, 0);
        prev[0] = 1; // start at position 0

        for (int step = 1; step <= steps; step++) {
            fill(curr.begin(), curr.end(), 0); // reset for this step
            for (int idx = 0; idx < maxPos; idx++) {
                long stay = prev[idx];
                long left = (idx > 0) ? prev[idx - 1] : 0;
                long right = (idx + 1 < maxPos) ? prev[idx + 1] : 0;

                curr[idx] = (stay + left + right) % MOD;
            }
            prev.swap(curr); // move curr → prev for next step
        }

        return prev[0];
    }
};
