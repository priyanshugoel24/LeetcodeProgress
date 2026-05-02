// Last updated: 02/05/2026, 22:40:18
class Solution {
public:
    int maximum69Number (int num) {
        
        string number = to_string(num);

        int n = number.length();


        int closest_ten = pow(10, n);
        
        //if all 9's
        if(closest_ten - 1 == num){
            return num;
        }

        //change the first occurence of 6
        int i = 0;

        while(i < n){

            if(number[i] != '9'){
                number[i] = '9';
                break;
            }

            i++;
        }

        int result = stoi(number);

        return result;
    }
};