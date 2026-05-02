// Last updated: 02/05/2026, 22:32:09
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        int n = nums.size();
        int minDistance = 2 * (n + 1);

        for(int i = 0; i < n - 2; i++){

            for(int j = i + 1; j < n -1 ; j++){

                if(nums[i] != nums[j]) continue;

                for(int k = j + 1; k < n; k++){

                    if(nums[j] == nums[k]){

                        minDistance = min(minDistance, 2 * (k - i));
                        break;
                    }
                }
            }
        }

        return minDistance == 2 * (n + 1) ? -1 : minDistance;
    }
};