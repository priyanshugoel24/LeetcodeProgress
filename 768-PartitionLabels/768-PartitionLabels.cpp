// Last updated: 02/05/2026, 22:43:29
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> partitionLengths;

        vector<int> freq(26, -1);

        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';
            freq[idx] = i;
        }

        int i = 0;

        while(i < n){
            int end = freq[s[i] - 'a'];

            int j = i;

            while(j < end){
                end = max(end, freq[s[j] - 'a']);
                j++;
            }

            partitionLengths.push_back(j-i+1);
            i = j+1;
        }

        return partitionLengths;
    }
};