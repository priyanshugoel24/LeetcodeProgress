// Last updated: 02/05/2026, 22:33:42
class Solution {
public:

    void changeInWindow(int num, vector<int>& vec, int val){
        for(int i = 0; i< 32; i++){
            if((num>> i) & 1){
                vec[i] += val;
            }
        }
    }

    int getDecimal(vector<int>& vec){
        int num = 0;

        for(int i = 0; i<32; i++){
            if(vec[i] > 0){
                num |= 1 << i;
            }
        }

        return num;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {

        int n = nums.size();
         
        int len = INT_MAX;

        int i = 0, j = 0;

        vector<int> vec(32, 0);
        //vec[i] = total no. of set bits in ith position

        while(j < n){
            changeInWindow(nums[j], vec, 1); // adding in curr window


            while(i <= j && getDecimal(vec) >= k){
                len = min(len, j-i+1);
                changeInWindow(nums[i], vec, -1); // subtracting in window 
                i++;
            }

            j++;
        }

        return len == INT_MAX ? -1 : len;
        
    }
};