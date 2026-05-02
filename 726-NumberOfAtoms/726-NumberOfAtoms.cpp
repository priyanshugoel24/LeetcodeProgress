// Last updated: 02/05/2026, 22:43:39
class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());

        int i = 0;
        while (i < n) {
            if (formula[i] == '(') {
                st.push(unordered_map<string, int>());
                i++;
            } else if (formula[i] == ')') {
                unordered_map<string, int> curr = st.top();
                st.pop();
                i++;

                string factor;
                while (i < n && isdigit(formula[i])) {
                    factor.push_back(formula[i]);
                    i++;
                }

                int multiplier = factor.empty() ? 1 : stoi(factor);
                for (auto& it : curr) {
                    curr[it.first] = it.second * multiplier;
                }

                for (auto& it : curr) {
                    st.top()[it.first] += it.second;
                }
            } else {
                string currElement;
                currElement += formula[i++];
                while (i < n && islower(formula[i])) {
                    currElement += formula[i++];
                }

                string currCount;
                while (i < n && isdigit(formula[i])) {
                    currCount += formula[i++];
                }

                int count = currCount.empty() ? 1 : stoi(currCount);
                st.top()[currElement] += count;
            }
        }

        map<string, int> sortedMap(st.top().begin(), st.top().end());
        string result;

        for (auto& it : sortedMap) {
            result += it.first;
            if (it.second > 1) {
                result += to_string(it.second);
            }
        }

        return result;
    }
};
