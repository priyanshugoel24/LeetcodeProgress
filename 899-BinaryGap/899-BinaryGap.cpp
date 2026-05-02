// Last updated: 02/05/2026, 22:42:44
class Solution {
public:
    int binaryGap(int n) {

        int lastIdx = -1, longestLength = 0;

        for (int idx = 0; idx < 32; idx++) {

            if (((n >> idx) & 1) > 0) {

                if (lastIdx >= 0) {

                    longestLength = max(longestLength, idx - lastIdx);
                }
                lastIdx = idx;
            }
        }

        return longestLength;
    }
};