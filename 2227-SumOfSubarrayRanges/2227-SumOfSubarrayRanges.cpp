// Last updated: 02/05/2026, 22:37:10
class Solution {
public:

    long long getSubarrayMaximum(vector<int>& nums){

        int n = nums.size();

        stack<int> st;
        vector<int> prevGreater(n, -1), nextGreater(n, n);

        for(int i = 0; i < n; i++){

            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }

            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = n - 1; i >= 0; i--){

            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }

            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sumMax = 0;
        for(int i =0; i < n; i++){

            long long left = i - prevGreater[i];
            long long right = nextGreater[i] - i;

            sumMax += (long long)(nums[i]) * left * right;
        }

        return sumMax;
    }
    long long getSubarrayMinimum(vector<int>& nums){

        int n = nums.size();

        stack<int> st;

        vector<int> prevSmaller(n, -1), nextSmaller(n, n);

        for(int i = 0; i < n; i++){

            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }

            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--){

            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }

            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sumMin = 0;

        for(int i =0; i < n; i++){

            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;

            sumMin += (long long)nums[i] * left * right;
        }

        return sumMin;
    }

    long long subArrayRanges(vector<int>& nums) {
          
        int n = nums.size();
        long long ans = getSubarrayMaximum(nums) - getSubarrayMinimum(nums);

        return ans;
    }
};