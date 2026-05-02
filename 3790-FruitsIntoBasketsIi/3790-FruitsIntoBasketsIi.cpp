// Last updated: 02/05/2026, 22:32:28
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        int n = fruits.size();

        vector<bool> isAvailable(n, true);

        int unplaced_fruits = 0;

        for(int i = 0; i < n; i++){

            int curr_fruit = fruits[i];

            bool isPlaced = false;
            for(int j = 0; j < n; j++){

                if(!isAvailable[j]) continue;

                if(baskets[j] >= curr_fruit){
                    isAvailable[j] = false;
                    isPlaced = true;
                    break;
                }

            }

            if(!isPlaced){
                unplaced_fruits++;
            }
        }

        return unplaced_fruits;
    }
};