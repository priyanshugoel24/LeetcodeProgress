// Last updated: 02/05/2026, 22:48:52
class Solution {
public:

    int first(vector<int>& nums, int target){

        int start = 0;
        int end = nums.size()-1;

        int val = -1;

        while( start <= end){

            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                val = mid;
                end = mid-1;
                
            }

            else if(nums[mid] < target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }

        return val;
    }

    int last(vector<int>& nums, int target){

        int start = 0;
        int end = nums.size()-1;

        int val = -1;

        while( start <= end){

            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                val = mid;
                start = mid+1;
            }

            else if(nums[mid] < target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }

            
        }

        return val;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ans;
        ans.push_back(first(nums, target));
        ans.push_back(last(nums, target));

        return ans;
    }
};