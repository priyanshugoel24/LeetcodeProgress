// Last updated: 02/05/2026, 22:45:04
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;

        for(int i = 0; i < n; i++) {
            char curr = num[i];
            // pop while current digit is smaller
            while(!st.empty() && k > 0 && st.top() > curr) {
                st.pop();
                k--;
            }
            st.push(curr);
        }

        // if still removals left, remove from end
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // build result
        string finalString = "";
        while(!st.empty()) {
            finalString.push_back(st.top());
            st.pop();
        }
        reverse(finalString.begin(), finalString.end());

        // remove leading zeros at the end
        while(finalString.size() > 0 && finalString[0] == '0') finalString.erase(finalString.begin());

        return finalString.empty() ? "0" : finalString;
    }
};
