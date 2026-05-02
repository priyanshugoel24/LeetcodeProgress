// Last updated: 02/05/2026, 22:48:54
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();

        // find the last index where nums[i] > nums[i - 1]
        int lastIdx = -1;
        for(int idx = n -1 ; idx > 0; idx--){

            if(nums[idx] > nums[idx - 1]){

                lastIdx = idx - 1;
                break;
            }
        }

        // find the index at which nums[idx] is just greater than nums[lastIdx]
        if(lastIdx != -1){
            int swapIdx = lastIdx;
            for(int idx = n - 1; idx >= lastIdx + 1; idx--){

                if(nums[idx] > nums[lastIdx]){
                    swapIdx = idx;
                    break;
                }
            }

            // swap nums[lastIdx] with nums[swapIdx]
            swap(nums[lastIdx], nums[swapIdx]);
        }

        // reverse the array right to the lastIdx
        reverse(nums.begin() + lastIdx + 1, nums.end());

    }
};