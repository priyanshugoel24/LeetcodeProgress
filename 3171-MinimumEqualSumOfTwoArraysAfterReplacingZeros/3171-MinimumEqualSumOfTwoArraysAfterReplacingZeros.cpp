// Last updated: 02/05/2026, 22:34:23
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);

        long long zeroesInFirst = 0, zeroesInSecond = 0;

        for(int i = 0; i < nums1.size(); i++){
            
            if(nums1[i] == 0){
                zeroesInFirst++;
            }
        }

        for(int i = 0; i < nums2.size(); i++){

            if(nums2[i] == 0){
                zeroesInSecond++;
            }
        }

       if(zeroesInFirst == 0 && zeroesInSecond == 0 && (sum1 != sum2)){
        return -1;
       }
       else if(zeroesInFirst == 0){
        if(sum2 + zeroesInSecond > sum1){
            return -1;
        }
       }else if(zeroesInSecond == 0){
        if(sum1 + zeroesInFirst > sum2){
            return -1;
        }
       }

        long long minSumPossible = max(sum1 + zeroesInFirst, sum2 + zeroesInSecond);

        return minSumPossible;

    }
};