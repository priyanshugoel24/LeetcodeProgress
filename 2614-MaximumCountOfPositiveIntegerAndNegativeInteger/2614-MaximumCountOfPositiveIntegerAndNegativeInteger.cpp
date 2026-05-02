// Last updated: 02/05/2026, 22:35:32
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;

        int firstPos = n;

        while( l <= r){

            int mid = l + (r-l)/2;

            if(nums[mid] >= 1){
                firstPos = mid;
                r = mid-1;
            }else{
                l = mid + 1;
            }
        }

        l = 0, r = n-1;

        int firstZero = n;

        while(l <= r){

            int mid = l + (r-l)/2;

            if(nums[mid] >= 0){
                firstZero = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        int posNumbers = n - firstPos;
        int negNumbers = firstZero;
       

        return max(posNumbers, negNumbers);
        
    }
};