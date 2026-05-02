// Last updated: 02/05/2026, 22:41:57
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;

        int flipCountforidx = 0;
        vector<bool> isFlipped(n, false);

        for(int i = 0; i<n; i++){
            if( i>= k && isFlipped[i-k]){
                flipCountforidx--;
            }

            if(flipCountforidx % 2 == nums[i]){

                if(i + k > n){
                    return -1;
                }

                flipCountforidx++;
                flips++;
                isFlipped[i] = true;
            }
        }

        return flips;
    }
};