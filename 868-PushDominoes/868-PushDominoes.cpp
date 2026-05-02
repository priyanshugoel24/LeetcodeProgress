// Last updated: 02/05/2026, 22:42:56
class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int n = dominoes.size(); // no of dominoes

        string result(n, ' '); // resultant domino configuration after pushing

        vector<int> closestRFromLeft(n); // index of R pushing domino closest to current index from left side
        vector<int> closestLFromRight(n); // index of L pushing domino closest to current index from right

        //start pushing dominoes from left
        for(int i = 0; i < n; i++){
            
            //we found a right pushing dominoe
            if(dominoes[i] == 'R'){
                closestRFromLeft[i] = i;
            }
            // current domino has no pushing effect
            else if(dominoes[i] == '.'){
                closestRFromLeft[i] = (i > 0) ? closestRFromLeft[i - 1] : -1;
            }else{
                //we have a left pushing domino so we don't count its effect
                closestRFromLeft[i] = -1;
            }
        }

        //start pushing dominoes from right
        for(int i = n - 1; i >= 0; i--){

            //we found a left pushing dominoe
            if(dominoes[i] == 'L'){
                closestLFromRight[i] = i;
            }
            // current domino has no pushing effect
            else if(dominoes[i] == '.'){
                closestLFromRight[i] = (i + 1 < n) ? closestLFromRight[i + 1] : -1;
            }else{
                //we have a right pushing domino so we don't count its effect
                closestLFromRight[i] = -1;
            }
        }

        //find the final configuration after pushing
        for(int i = 0; i < n; i++){
            
            // if the domino is already pushed
            if(dominoes[i] != '.') {
                result[i] = dominoes[i];
                continue;
            }

            //pushing effect from right
            int distRightFromL = (closestLFromRight[i] == -1) ? INT_MAX : abs(i - closestLFromRight[i]);

            //pushing effect from left
            int distLeftFromR = (closestRFromLeft[i] == -1) ? INT_MAX : abs(i - closestRFromLeft[i]);

            // if no force from both sides
            if(closestRFromLeft[i] == -1 && closestLFromRight[i] == -1){
                result[i] = '.';
            }
            // if only force from right side
            else if(distLeftFromR < distRightFromL){
                result[i] = 'R';
            }
            // if only force from left side
            else if(distRightFromL < distLeftFromR){
                result[i] = 'L';
            }
            //if equal force from both sides
            else{
                result[i] = '.';
            }
        }

        //return the final domino configuration
        return result;
    }
};