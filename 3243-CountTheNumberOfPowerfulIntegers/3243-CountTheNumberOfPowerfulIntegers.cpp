// Last updated: 02/05/2026, 22:34:03
class Solution {
public:
    long long solve(string& str, string& suffix, int limit){

        if(str.length() < suffix.length()){
            return 0;
        }

        long long count = 0;

        string trailString = str.substr(str.length() - suffix.length());

        int remainingLen = str.length() - suffix.length();

        for(int i = 0; i < remainingLen; i++){

            int digit = str[i] - '0';

            if(digit <= limit){
                count += digit * pow(limit + 1, remainingLen - i - 1);
            }else{
                count += pow(limit + 1, remainingLen - i);
                return count;
            }
        }

        if(trailString >= suffix){
            count += 1;
        }

        return count;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        
        string startStr = to_string(start - 1);
        string finishStr = to_string(finish);

        return solve(finishStr, s, limit) - solve(startStr, s, limit);
    }
};