// Last updated: 02/05/2026, 22:44:48
class Solution {
public:
    int countNumbersInRange(int n, long currNo) {
        long nextNo = currNo + 1;
        int count = 0;

        while (currNo <= n) {
            count += min(n - currNo + 1, nextNo - currNo); 
            currNo *= 10;
            nextNo *= 10;
        }

        return count;
    }

    int findKthNumber(int n, int k) {
        int currNo = 1;
        k--; // Since we already consider "1" as the first number

        while (k > 0) {
            int count = countNumbersInRange(n, currNo);

            if (count <= k) {
                // Skip this entire subtree
                k -= count;
                currNo++;
            } else {
                // Move deeper in the current subtree
                k--;
                currNo *= 10;
            }
        }

        return currNo;
    }
};