// Last updated: 02/05/2026, 22:44:31
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> nextGreaterOfIdx(n);

        stack<int> st;

        for(int idx = 2*n - 1; idx >= 0; idx--){

            while(!st.empty() && st.top() <= nums[idx % n]){

                st.pop();
            }

            if((int)idx < n){

                nextGreaterOfIdx[idx] = (st.empty()) ? -1 : st.top();
            }

            st.push(nums[idx % n]);
        }

        return nextGreaterOfIdx;
    }
};