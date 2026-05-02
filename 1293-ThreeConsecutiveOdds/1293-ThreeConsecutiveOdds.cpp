// Last updated: 02/05/2026, 22:41:03
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        int countOdd = 0;

        for(int i = 0; i < arr.size(); i++){

            if(arr[i] % 2 == 0){
                countOdd = 0;
            }else{
                countOdd++;
            }

            if(countOdd >= 3){
                return true;
            }
        }

        return false;
    }
};