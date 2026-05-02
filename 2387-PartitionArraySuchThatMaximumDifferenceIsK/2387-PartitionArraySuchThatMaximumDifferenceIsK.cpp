// Last updated: 02/05/2026, 22:36:33
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int min_partitions = 1;

        int curr = nums[0];

        for(int i = 1; i < n; i++){

            if(nums[i] - curr > k){
                min_partitions++;
                curr = nums[i];
            }
        }

        return min_partitions;
    }
};