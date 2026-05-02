// Last updated: 02/05/2026, 22:32:17
class Solution {
public:
    string processStr(string s) {
        
        int len = s.length();
        string result = "";

        for(int idx = 0; idx < len; idx++){

            char ch = s[idx];

            //case 1 : a lower case letter, append it to result
            if(ch >= 'a' && ch <= 'z'){

                result += ch;

            }else if(ch == '*'){ // case 2 : delete last character from result
                
                if(!result.empty()){
                    result.pop_back();
                }
                
            }else if(ch == '#'){ // case 3 : add result to itself

                result += result;
            }else{

                reverse(begin(result), end(result));
            }


        }

        return result;
    }
};