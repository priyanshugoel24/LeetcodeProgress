// Last updated: 02/05/2026, 22:44:33
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        unordered_map<int,int> map;
        vector<int> ans(nums1.size(), -1);

        for(int i = nums2.size()-1; i>=0; i--){

            int num = nums2[i];

            while(!st.empty() && st.top() <= num){
                st.pop();
            }
            if(!st.empty()){
                map[nums2[i]] = st.top();
            }
            else{
                map[nums2[i]] = -1;
            }

            st.push(nums2[i]);
        }

        for(int i = 0; i<nums1.size(); i++){

            ans[i] = map[nums1[i]];
        }

        return ans;
        
    }
};