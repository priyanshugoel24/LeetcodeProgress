// Last updated: 02/05/2026, 22:39:59
class Solution {
public:
    int digitsSum(int num){

        int sum = 0; //required sum of digits

        while(num){

            sum += num % 10; //adding the ith place digit to sum
            num = num / 10; //shifiting the number for next digit
        }

        return sum;
    }
    int countLargestGroup(int n) {
        
        unordered_map<int, int> freq;
        //freq[i] -> denotes count of elements having sum of digits equal to i

        int largestGroup = 0; // largest possible sum of digits
        int countOfLargestGroup = 0; // count of largest possible sum of digits which is the answer

        for(int num = 1; num <= n; num++){

            //find the sum of digits for the number
            int sum_of_digits = digitsSum(num);

            //update the map
            freq[sum_of_digits]++;

            //check if it is equal to largest possible sum of digits
            if(freq[sum_of_digits] == largestGroup){
                countOfLargestGroup++;
            }

            //check if curr sum of digits is greater than previous largest group
            else if(freq[sum_of_digits] > largestGroup){
                largestGroup = freq[sum_of_digits];
                countOfLargestGroup = 1;
            }

        }

        return countOfLargestGroup;

    }
};