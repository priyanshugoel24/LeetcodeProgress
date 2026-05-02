// Last updated: 02/05/2026, 22:33:52
class Solution {
public:
    string triangleType(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        //check if we can make triangle
        if(nums[0] + nums[1] <= nums[2]){
            return "none";
        }

        set<int> st;

        for(int num : nums){
            st.insert(num);
        }

        int size = st.size();

        switch(size){

            case 1 : return "equilateral";
            break;

            case 2 : return "isosceles";
            break;

            case 3 : return "scalene";
            break;
        }

        return "";
    }
};