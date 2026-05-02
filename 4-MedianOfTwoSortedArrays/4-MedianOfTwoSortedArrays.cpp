// Last updated: 02/05/2026, 22:49:20
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size(), n = nums2.size();

        if(m > n) return findMedianSortedArrays(nums2, nums1);

        int l = 0, r = m;

        while(l <= r){

            int nums_from_1 = l + (r - l) / 2;

            int nums_from_2 = (m + n + 1) / 2  - nums_from_1;

            // left partition
            int x1 = (nums_from_1 == 0) ? INT_MIN : nums1[nums_from_1 - 1];
            int x2 = (nums_from_2 == 0) ? INT_MIN : nums2[nums_from_2 - 1];

            //right partition
            int x3 = (nums_from_1 == m) ? INT_MAX : nums1[nums_from_1];
            int x4 = (nums_from_2 == n) ? INT_MAX : nums2[nums_from_2];

            if(x1 <= x4 && x2 <= x3){

                if((m + n) % 2 == 1){
                    return max(x1, x2);
                }

                return (max(x1, x2) + min(x3, x4)) / 2.0;
            }

            if(x1 > x4){
                r = nums_from_1 - 1;
            }else{
                l = nums_from_1 + 1;
            }

        }

        return -1;
    }
};