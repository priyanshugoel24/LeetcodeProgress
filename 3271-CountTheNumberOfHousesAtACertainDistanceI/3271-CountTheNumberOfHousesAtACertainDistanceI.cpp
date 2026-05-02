// Last updated: 02/05/2026, 22:33:58
class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> result(n, 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int normal = j - i;

                int via_x_y = abs(i - x) + 1 + abs(y - j);
                int via_y_x = abs(i - y) + 1 + abs(x - j);

                int d = min({normal, via_x_y, via_y_x});

                result[d - 1] += 2;  // both (i,j) and (j,i)
            }
        }

        return result;
    }
};
