// Last updated: 02/05/2026, 22:45:47
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        f(0, "", 0, 0, num, target, result);
        return result;        
    }
    void f(int i , string sumPath, long sum, long prev, string num, int target, vector<string>& result){

        if(i == num.size()){
            if(sum == target) result.push_back(sumPath);
            return;
        }

        for(int j = i; j<num.size(); j++){

            if(j > i && num[i] == '0') break;

            long number = stol(num.substr(i, j-i+1));
            string tempPath = num.substr(i, j-i+1);

            if(i == 0) f(j+1, tempPath, number, number, num, target, result);
            else{

                //addition
                f(j+1, sumPath + '+' + tempPath,sum+number, number, num, target, result);
                //subtraction
                f(j+1, sumPath + '-' + tempPath, sum-number, -number, num, target, result);
                //multiplication
                f(j+1, sumPath + '*' + tempPath, sum - prev + (prev*number), prev*number, num, target, result);
            }
        }
    }
};