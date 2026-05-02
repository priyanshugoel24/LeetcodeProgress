// Last updated: 02/05/2026, 22:46:57
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int currProduct = 1, maxProduct = INT_MIN;
        int n = nums.size();

        for(int i = 0; i<n; i++){

           currProduct = currProduct * nums[i];
           maxProduct = max(maxProduct, currProduct);
           if(currProduct == 0) currProduct = 1;
           

           
        }
        currProduct = 1;

        for(int i = n-1; i>=0; i--){

            currProduct = currProduct * nums[i];
           maxProduct = max(maxProduct, currProduct);
           if(currProduct == 0) currProduct = 1;
           
            
        }

        return maxProduct;
        
    }
};