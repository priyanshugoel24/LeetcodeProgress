// Last updated: 02/05/2026, 22:45:58
class Solution {
public:
    vector<int> solve(string s){

        vector<int> result;

        for(int i = 0; i<s.length(); i++){
            if(s[i] == '+' || s[i] == '-' || s[i] == '*'){
                vector<int> left_results = solve(s.substr(0, i));
                vector<int> right_results = solve(s.substr(i+1));

                for(int &x : left_results){
                    for(int &y : right_results){
                        switch(s[i]){
                            case '+' :
                                result.push_back(x+y);
                                break;
                            case '-' : 
                                result.push_back(x-y);
                                break;
                            case '*':
                                result.push_back(x*y);
                                break;
                                                   
                        }
                    }
                }
            }
        }

        if(result.empty()){
            result.push_back(stoi(s));
        }

        return result;
    }
    vector<int> diffWaysToCompute(string expression) {
        
        return solve(expression);
    }
};