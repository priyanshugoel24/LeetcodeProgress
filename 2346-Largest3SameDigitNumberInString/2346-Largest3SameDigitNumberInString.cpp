// Last updated: 02/05/2026, 22:36:44
class Solution {
public:
    string largestGoodInteger(string num) {
        
        int n = num.length();

        string max_good_integer = "";

        int i = 0;

        while(i < n){

            char curr_digit = num[i];

            int j = i + 1;

            while(j < n && num[j] == curr_digit){
                j++;
            }

            int curr_length_good_integer = j - i;

            if(j - i == 3){
                
                string curr_good_integer = num.substr(i, curr_length_good_integer);
                max_good_integer = max(max_good_integer, curr_good_integer);
            }

            i++;
        }

        return max_good_integer;
    }
};