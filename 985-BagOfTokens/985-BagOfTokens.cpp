// Last updated: 02/05/2026, 22:42:09
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n = tokens.size();
        int intial_score = 0;

        int max_score = 0;

        sort(begin(tokens), end(tokens));

        int l = 0, r = n - 1; // left pointer to increase score, right pointer to increase 
        
        while(l <= r){
            
            if(power >= tokens[l]){
                power -= tokens[l];
                intial_score += 1;
                l++;

                max_score = max(max_score, intial_score);

            }else if(intial_score >= 1){

                power += tokens[r];
                intial_score -= 1;
                r--;
            }else{

                return max_score;
            }

        }

        return max_score;

    }
};