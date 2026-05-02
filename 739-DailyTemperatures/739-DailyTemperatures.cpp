// Last updated: 02/05/2026, 22:43:35
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st; 

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prev_day = st.top();
                st.pop();
                result[prev_day] = i - prev_day;
            }
            st.push(i);
        }

        return result;
    }
};
