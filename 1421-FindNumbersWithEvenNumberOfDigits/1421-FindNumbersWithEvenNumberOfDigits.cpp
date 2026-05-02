// Last updated: 02/05/2026, 22:40:25
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int evenDigitNumbers = 0; // count of numbers having even no of digits in the array

        for(int &num : nums){

            //check if the current num contain even no of digits
            int digits = floor(log10(num)) + 1; // this is also equal to ceil(log10(num))

            // if the no of digits are even increment result
            if(digits % 2 == 0){
                evenDigitNumbers += 1;
            }
        }

        //return the final result
        return evenDigitNumbers;
    }
};