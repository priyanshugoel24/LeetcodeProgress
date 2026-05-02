// Last updated: 02/05/2026, 22:46:12
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();
        vector<int> res;
        int cntr1 = 0, cntr2 = 0, ele1 = -1, ele2 = -1;

        for(int i = 0; i < n; i++){

            if(cntr1 == 0 && nums[i] != ele2){
                cntr1 = 1;
                ele1 = nums[i];
            }else if(cntr2 == 0 && nums[i] != ele1){
                cntr2 = 1;
                ele2 = nums[i];
            }else if(nums[i] == ele1){
                cntr1++;
            }else if(nums[i] == ele2){
                cntr2++;
            }else{
                cntr1--, cntr2--;
            }
        }

        int cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < n; i++){

            if(nums[i] == ele1){
                cnt1++;
            }else if(nums[i] == ele2){
                cnt2++;
            }
        }

        if(cnt1 > n/3) res.push_back(ele1);
        if(cnt2 > n/3) res.push_back(ele2);

        sort(begin(res), end(res));

        return res;
    }
};