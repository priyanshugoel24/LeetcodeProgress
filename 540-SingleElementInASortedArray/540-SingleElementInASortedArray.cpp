// Last updated: 02/05/2026, 22:44:26
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end-start)/2;

        while(start < end){

            if(mid % 2 == 1){
                mid--;
            }
            if(nums[mid] != nums[mid+1] ){
                end = mid;
            }
            else{
                start = mid+2;
            }

            mid = start + (end-start)/2;
        }

        return nums[mid];

          

        
    }
};