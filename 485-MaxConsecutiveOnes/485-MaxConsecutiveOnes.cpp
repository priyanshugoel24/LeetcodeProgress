// Last updated: 02/05/2026, 22:44:39
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

    int n = nums.size();
    int cnt = 0;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        if(nums[i] == 1){
            cnt++;
        }
       else{
         maxi = max(maxi, cnt);
         cnt = 0;
       }
    }
     maxi = max(maxi, cnt);
    if(maxi > n) return -1;

    return maxi;
        
    }
};