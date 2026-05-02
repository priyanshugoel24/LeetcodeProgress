// Last updated: 02/05/2026, 22:41:24
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        int n = dominoes.size(); // number of dominoes
        int equivDominoPairs = 0; // number of equivalent domino pairs

        unordered_map<int, int> freq;
        // freq[key] : key is the unique identifier for a domino pair
        // key is created by sorting the two values and encoding as: min(a,b) * 10 + max(a,b)

        for(int i = 0; i < n; i++) {
            int a = dominoes[i][0];
            int b = dominoes[i][1];

            // create a key that treats [a,b] and [b,a] as the same
            int key = min(a, b) * 10 + max(a, b);

            // update the frequency of this key in the map
            freq[key]++;
        }

        // iterate through the map to count number of valid pairs
        for(auto it : freq) {
            int count = it.second; // number of dominoes with same key (i.e., same unordered pair)
            
            // if there are more than 1, we can form C(count, 2) = count * (count - 1) / 2 pairs
            if(count > 1) {
                equivDominoPairs += (count * (count - 1)) / 2;
            }
        }

        // return the final answer
        return equivDominoPairs;
    }
};