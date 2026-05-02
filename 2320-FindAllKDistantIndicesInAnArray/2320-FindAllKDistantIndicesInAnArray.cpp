// Last updated: 02/05/2026, 22:36:47
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        int n = nums.size();

        set<int> indices;

        for(int i = 0; i < n; i++){

            if(nums[i] == key){

                for(int j = i - k; j <= i + k; j++){

                    if(j >= 0 &&  j < n){
                        indices.insert(j);
                    }
                }
            }
        }

        vector<int> vec(indices.begin(), indices.end());

        return vec;

    }
};