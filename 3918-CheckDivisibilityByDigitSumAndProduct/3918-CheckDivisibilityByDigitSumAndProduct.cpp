// Last updated: 02/05/2026, 22:32:20
class Solution {
public:
    bool checkDivisibility(int n) {
        
        int sum_of_digits = 0;
        int product_of_digits = 1;

        int temp = n;

        while(temp > 0){

            sum_of_digits += temp % 10;
            product_of_digits *= temp % 10;

            temp = temp / 10;
        }

        int divisor = sum_of_digits + product_of_digits;

        if(n % divisor == 0){
            return true;
        }

        return false;
    }
};