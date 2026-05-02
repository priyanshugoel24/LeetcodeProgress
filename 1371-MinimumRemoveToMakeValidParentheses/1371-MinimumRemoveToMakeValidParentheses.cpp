// Last updated: 02/05/2026, 22:40:40
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n = s.length();

        string result = "";

        // iterate from left to right -> eliminate extra close brackets
        int open = 0;
        for(int i = 0; i < n; i++){

            if(s[i] >= 'a' && s[i] <= 'z'){
                result.push_back(s[i]);
            }else if(s[i] == '('){
                open++;
                result.push_back(s[i]);
            }else if(open > 0){
                open--;
                result.push_back(s[i]);
            }
        }

        // iterate from right to left -> eliminate extra open brackets
        string final_result = "";

        int close = 0;

        for(int i = result.length() - 1; i >= 0; i--){
            if(result[i] >= 'a' && result[i] <= 'z'){
                final_result.push_back(result[i]);
            }else if(result[i] == ')'){
                close++;
                final_result.push_back(result[i]);
            }else if(close > 0){
                close--;
                final_result.push_back(result[i]);
            }
        }

        reverse(begin(final_result), end(final_result));

        return final_result;
    }
};