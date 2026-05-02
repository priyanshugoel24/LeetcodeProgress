// Last updated: 02/05/2026, 22:36:01
class Solution {
public:
    int partitionString(string s) {
        int mask = 0;  // Bitmask to track characters in the current partition
        int count = 0;

        for (char ch : s) {
            int bit = ch - 'a';
            if ((mask >> bit) & 1) {
                // Char already seen in this partition
                count++;
                mask = 0;
            }
            mask |= (1 << bit);  // Mark character as seen
        }

        return count + 1;  // Add last partition
    }
};
