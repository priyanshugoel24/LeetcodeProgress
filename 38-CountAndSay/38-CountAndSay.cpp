// Last updated: 02/05/2026, 22:48:46
class Solution {
public:
    string countAndSay(int n) {
        
        //base case : 1 will be said as '1' only
        if(n == 1){
            return "1";
        }

        //recursion call to n - 1
        string say = countAndSay(n -1);

        string s = "";
        for(int i = 0; i < say.length(); i++){
            char ch = say[i];

            int count = 1;

            while(i < say.length() -1 && say[i] == say[i + 1]){
                count++;
                i++;
            }

            s += to_string(count) + string(1, ch);   
        }

        return s;
    }
};