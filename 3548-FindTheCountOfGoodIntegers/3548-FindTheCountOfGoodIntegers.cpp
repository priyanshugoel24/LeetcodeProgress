// Last updated: 02/05/2026, 22:33:15
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        
        // set to store a good k palindromic string that also generates all the valid permutations for good integers
        unordered_set<string> goodString;

        int d = (n + 1 ) / 2; // no of digits in left half of the string
        int start = pow(10, d-1); // starting range of n length good integers
        int end = pow(10, d) - 1; // ending range of n length good integers

        long long goodIntegers = 0; // goodIntegers in the required range

        for(int num = start; num <= end; num++){

            string leftHalf = to_string(num);
            string fullNo = "";

            //even length palindrome
            if(n % 2 == 0){
                string rightHalf = leftHalf;
                reverse(rightHalf.begin(), rightHalf.end());
                fullNo = leftHalf + rightHalf;
            } else{
                //odd length palindrome
                string rightHalf = leftHalf.substr(0, d-1);
                reverse(rightHalf.begin(), rightHalf.end());
                fullNo = leftHalf + rightHalf;
            }


            long long palindromicInt = stoll(fullNo); // x palindromic integer

            // if not divisible by k continue to next number
            if(palindromicInt % k != 0){
                continue;
            }

            // sort the k palindromic integer
            sort(fullNo.begin(), fullNo.end());

            //push to set after sorting to avoid duplicates
            goodString.insert(fullNo);
        }

        //factorial of all possible digits
        vector<long long> factorial(11, 1);
        for(int i = 1; i < 11; i++){
            factorial[i] = factorial[i-1] * i;
        }

        for(const string &s : goodString){

            vector<int> count(10, 0); // freq of every number

            //updating the frequency of every number
            for(const char &ch : s){
                count[ch - '0']++;
            }

            int totalDigits = s.length();
            int zeroDigits = count[0];
            int nonZeroDigits = totalDigits - zeroDigits;

            long long permutation = (nonZeroDigits) * factorial[totalDigits - 1]; //possible permutations with the string

            // to avoid duplicates 
            for(int i = 0; i < 10; i++){
                permutation /= factorial[count[i]];
            }

            //increment the result by the count of permutations calculated
            goodIntegers += permutation;
        }

        return goodIntegers;


    }
};