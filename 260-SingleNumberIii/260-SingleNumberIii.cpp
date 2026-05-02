// Last updated: 02/05/2026, 22:45:54
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long num =0;
        for(int i=0;i<nums.size();i++){
            num ^= nums[i];
        }
        long int rem =  num&(-num);

        long int b1=0;
        long int b2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&rem){
              
                b1^=nums[i];
            }
            else{
               

                b2^=nums[i];

            }
        }
        vector<int> ans;
        ans.push_back(b1);
        ans.push_back(b2);

        return ans;
        
    }
};