// Last updated: 02/05/2026, 22:32:10
class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int, int> freqOfDigit;

        while (n > 0) {
            int digit = n % 10;
            freqOfDigit[digit]++;
            n /= 10;
        }

        int minFreqDigit = INT_MAX;
        int minFreq = INT_MAX;

        for (auto& [digit, count] : freqOfDigit) {
            if (count < minFreq) {
                minFreq = count;
                minFreqDigit = digit;
            } else if (count == minFreq) {
                minFreqDigit = min(minFreqDigit, digit);
            }
        }

        return minFreqDigit;
    }
};
