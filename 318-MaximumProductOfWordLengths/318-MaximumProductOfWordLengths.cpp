// Last updated: 02/05/2026, 22:45:32
class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n = words.size();

        vector<int> mask(n, 0);

        for(int i = 0; i < n; i++){

            for(char ch : words[i]){

                mask[i] |= (1 << (ch - 'a'));
            }
        }

        int maxProd = 0;

        for(int i = 0; i < n - 1; i++){

            for(int j = i + 1; j < n; j++){

                if((mask[i] & mask[j]) == 0){
                    
                    maxProd = max(maxProd,(int)(words[i].size() * words[j].size()));

                }
            }
        }

        return maxProd;
    }
};