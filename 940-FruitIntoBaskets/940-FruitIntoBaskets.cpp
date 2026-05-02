// Last updated: 02/05/2026, 22:42:24
class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size();

        unordered_map<int, int> count;
        int max_length = 0;
        int i = 0;

        for (int j = 0; j < n; ++j) {
            count[fruits[j]]++;

            // Shrink window if more than 2 types of fruits
            while (count.size() > 2) {
                count[fruits[i]]--;
                if (count[fruits[i]] == 0) {
                    count.erase(fruits[i]);
                }
                i++;
            }

            max_length = max(max_length, j - i + 1);
        }

        return max_length;
    }
};
