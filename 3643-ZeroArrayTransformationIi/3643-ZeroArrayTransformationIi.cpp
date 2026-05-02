// Last updated: 02/05/2026, 22:32:56
class Solution {
public:
    bool isZeroArrayPossible(vector<int> nums, vector<vector<int>>& queries, int k){

        int n = nums.size();
        vector<int> diff(n+1, 0);

        for(int i = 0; i<k; i++){
            int start = queries[i][0], end = queries[i][1], x = queries[i][2];

            diff[start] -= x;
            diff[end+1] += x;
        }

        //calcualte prefix sum for diff array
        int cumSum = diff[0];
        for(int i = 1; i<=n; i++){
            diff[i] += cumSum;
            cumSum = diff[i];
        }

        //update nums array to check if all zero possible
        for(int i = 0; i<n; i++){
            nums[i] += diff[i];
            if(nums[i] > 0) return false;
        }

        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();

        bool isAllZero = true;
        for(int i = 0; i<n; i++){
            if(nums[i] != 0) isAllZero = false;
        }

        if(isAllZero) return 0;

        //applying binary search for choosing suitable k ie. no of min queries

        int l = 1, r = queries.size();

        int minOperations = -1;

        while(l <= r){

            int mid = l + (r-l)/2;

            if(isZeroArrayPossible(nums, queries, mid)){
                minOperations = mid;
                r = mid-1;
            } else{
                l = mid+1;
            }
        }

        return (minOperations == -1) ? -1 : minOperations;
    }
};