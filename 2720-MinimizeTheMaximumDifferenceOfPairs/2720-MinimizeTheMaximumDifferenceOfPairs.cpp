// Last updated: 02/05/2026, 22:35:02
class Solution {
public:
    bool isPossible(int mid, vector<int>& nums, int p){

        int i = 0;
        int no_of_pairs = 0;

        while(i < nums.size() - 1){

            if(nums[i + 1] - nums[i] <= mid){
                no_of_pairs++;
                i = i + 2;
            }else{
                i++;

            }
        }

        if(no_of_pairs >= p){
            return true;
        }
        

        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int l = 0, r = (nums[n - 1] - nums[0]);

        int sum = INT_MAX;

        while(l <= r){

            int mid = l + (r - l) / 2;

            if(isPossible(mid, nums, p)){
                sum = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return sum;
    }
};