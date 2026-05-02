// Last updated: 02/05/2026, 22:43:15
class Solution {
public:
    
    bool isGoodNumber(int num) {
        int mapping[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};

        bool allSameAfterRotation = true;

        while (num > 0) {
            int digit = num % 10;

            if (mapping[digit] == -1) {
                return false; // invalid digit
            }

            if (mapping[digit] == 1) {
                allSameAfterRotation = false; // changes after rotation
            }

            num /= 10;
        }

        return !allSameAfterRotation;
    }

    int rotatedDigits(int n) {
        int count = 0;

        for (int num = 1; num <= n; num++) {
            if (isGoodNumber(num)) {
                count++;
            }
        }

        return count;
    }
};