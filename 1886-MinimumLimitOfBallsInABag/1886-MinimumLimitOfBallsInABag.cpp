// Last updated: 02/05/2026, 22:38:31
class Solution {
public:
    bool isPossible(vector<int>& nums, int maxOperations, int mid){

        int totalOps = 0; // to bring each number <= mid

        for(int &num  : nums){

            int ops = num / mid;

            if(num % mid == 0) ops -= 1;

            totalOps += ops;
        }

        return totalOps <= maxOperations;

    }
    int minimumSize(vector<int>& nums, int maxOperations) {

        int l = 1, r = *max_element(nums.begin(), nums.end());

        int result = r;

        while(l < r){
            int mid = l + (r-l) / 2;

            if(isPossible(nums, maxOperations,mid)){
                r = mid;
                result = r;
            } else{
                l = mid+1;
            }
        }

        return result;
        
    }
};