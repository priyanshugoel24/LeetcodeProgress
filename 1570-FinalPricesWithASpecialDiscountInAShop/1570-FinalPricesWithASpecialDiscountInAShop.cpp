// Last updated: 02/05/2026, 22:39:33
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n = prices.size();

        for(int i = 0; i<n; i++){
            while(!st.empty() && prices[i] <= prices[st.top()]){
                int idx = st.top();
                st.pop();
                prices[idx] -= prices[i];
            }
            st.push(i);
        }

        return prices;
        
    }
};