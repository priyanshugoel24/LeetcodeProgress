// Last updated: 02/05/2026, 22:37:08
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        
        int n = fruits.size();

        vector<int> prefixSum(n);
        vector<int> positions(n);

        for(int i = 0; i < n; i++){
            positions[i] = fruits[i][0];

            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i - 1] : 0);
        }

        int max_fruits = 0;

        for(int d = 0; d <= k / 2; d++){

            // case 1 : move d steps to the left and k - d to right
            int remaining = k - 2*d;
            int i = startPos - d;
            int j = startPos + remaining;

            int left = lower_bound(begin(positions), end(positions), i) - begin(positions);
            int right = upper_bound(begin(positions), end(positions), j) - begin(positions) - 1;

            if(left <= right){
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                max_fruits = max(max_fruits, total);
            }

            // case 2 : move d steps to right and k - d to left
            i = startPos - remaining;
            j = startPos + d;

            left = lower_bound(begin(positions), end(positions), i) - begin(positions);
            right = upper_bound(begin(positions), end(positions), j) - begin(positions) - 1;

            if(left <= right){
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                max_fruits = max(max_fruits, total);
            }
        }

        return max_fruits;
    }
};