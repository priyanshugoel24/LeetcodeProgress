// Last updated: 02/05/2026, 22:36:37
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        int n = capacity.size();

        vector<int> extraCapacity(n);
        for(int i = 0; i < n; i++){

            extraCapacity[i] = capacity[i] - rocks[i];
        }

        sort(begin(extraCapacity), end(extraCapacity));

        int full_bags = 0;

        for(int i = 0; i < n; i++){


            if(additionalRocks <= 0){
                break;
            }

            if(extraCapacity[i] <= additionalRocks){
                full_bags++;
            }

            additionalRocks -= extraCapacity[i];
        }

        return full_bags;


    }
};