// Last updated: 02/05/2026, 22:42:05
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        stack<int> st;

        st.push(0);

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] < nums[st.top()]) st.push(i);
        }

        int ramp = 0;

        for(int i = nums.size()-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                ramp = max(ramp, i - st.top());
                st.pop();
            }
        }

        return ramp;
    }
};