// Last updated: 02/05/2026, 22:32:57
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();

        vector<int> diff(n+1, 0);

        for(auto query: queries){
            int start = query[0], end = query[1];

            diff[start] -= 1;
            diff[end+1] += 1;

        }

         //calculate prefixSum for diff array
        int cumSum = diff[0];
        for(int i = 1; i<=n; i++){
            diff[i] += cumSum;
            cumSum = diff[i];
        }

        for(int i = 0; i<n; i++){

            if(nums[i] == 0) continue;
            nums[i] += diff[i];
            if(nums[i] > 0) return false;
            // if the number is negative it means it reached 0 and we can stop applying query once it has reached 0 as only subset has to be selected
        }

        return true;

        

       




    }
};