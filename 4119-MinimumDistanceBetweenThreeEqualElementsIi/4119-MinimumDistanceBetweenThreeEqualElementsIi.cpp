// Last updated: 02/05/2026, 22:32:13
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        int n = nums.size();
        int minDistance = 2 * (n + 1);

        unordered_map<int, vector<int>> tuples;

        for(int i = 0; i < n; i++){

            tuples[nums[i]].push_back(i);
        }

        for(auto& it : tuples){

            vector<int> vec = it.second;

            if(vec.size() < 3) continue;

            
            for(int j = 2; j < vec.size(); j++){

                int currDistance = 2 * (vec[j] - vec[j - 2]);

                minDistance = min(minDistance, currDistance);
            }


        }

        return minDistance == 2 * (n + 1) ? -1 : minDistance;
    }
};