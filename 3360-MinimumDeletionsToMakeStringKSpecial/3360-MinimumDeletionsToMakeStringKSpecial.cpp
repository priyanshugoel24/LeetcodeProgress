// Last updated: 02/05/2026, 22:33:47
class Solution {
public:
    int minimumDeletions(string word, int k) {
        
        vector<int> freq(26, 0);

        for(char ch : word){
            freq[ch - 'a']++;
        }

        int result = word.length();

        for(int i = 0; i < 26; i++){

            int deletions = 0;

            for(int j = 0;  j< 26; j++){

                if(i == j) continue;

                if(freq[j] < freq[i]){
                    deletions += freq[j];
                }else if(abs(freq[j] - freq[i]) > k){
                    deletions += abs(freq[j] - freq[i] - k);
                }
            }

            result = min(result, deletions);
        }


        return result;
    }
};