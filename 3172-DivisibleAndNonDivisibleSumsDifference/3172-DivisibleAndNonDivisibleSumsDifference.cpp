// Last updated: 02/05/2026, 22:34:22
class Solution {
public:
    int differenceOfSums(int n, int m) {

        int num2 = 0;
        int num1 = 0;

        for(int i = 1; i <= n; i++){

            if(i % m == 0){
                num2 += i;
            }else{
                num1 += i;
            }
        }

        int requiredSum = num1 - num2;

        return requiredSum;
    }
};