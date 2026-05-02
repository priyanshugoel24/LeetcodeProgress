// Last updated: 02/05/2026, 22:42:00
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
        long long no_of_operations = 0;

        while(target > startValue){

            if(target % 2 == 0){

                target = target / 2;
            }else{
                target = target + 1;
            }

            no_of_operations++;
        }

        return no_of_operations - (target - startValue);
    }
};