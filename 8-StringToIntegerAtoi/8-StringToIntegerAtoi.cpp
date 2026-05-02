// Last updated: 02/05/2026, 22:49:16
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();

        // array to map corresponding digit
        char mp[] = {'0','1','2','3','4','5','6','7','8','9'};

        string res = "";

        bool sign = false;  //  detect sign of number (false -> +, true -> -)
        bool flagSpace = true, flagSign = true; // indicators 

        for(auto ch : s) {
            if(ch == ' ' && flagSpace) continue;    // ignoring leading whitespaces
            else if((ch == '-' || ch == '+') && flagSign){  //  detecting Sign of number
                if(ch == '-') sign = true;
                flagSpace = false;
                flagSign = false;
            } 
            else if((ch%'0' < 10) && mp[ch%'0'] == ch) {    // constructing required digit string
                res += ch;
                if(flagSpace) flagSpace = false;
                if(flagSign) flagSign = false;
            } 
            else{   //  any other character is encountered
                if(res == "") return 0;
                break;
            }
        }

        long long ans = 0;
        for(auto ch : res) {
            ans = ans*10 + (ch%'0');

            // edge cases
            if(sign && -1*ans <= INT_MIN) return INT_MIN;
            if(!sign && ans >= INT_MAX) return INT_MAX;
            
        }

        if(sign) ans *= -1; //  change sign of number
        return (int)ans;
    }
};