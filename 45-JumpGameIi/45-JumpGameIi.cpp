// Last updated: 02/05/2026, 22:48:39
class Solution {
public:
    int jump(vector<int>& nums) {

        int jumps = 0, l= 0, r=0, n = nums.size();

        while( r < n-1){

            int farthest = 0;

            for(int ind = l; ind <=r; ind++){

                farthest = max(farthest, nums[ind] + ind);
            }
            l = r+1, r = farthest, jumps++;
        }

        return jumps;
        
    }
};