// Last updated: 02/05/2026, 22:34:48
class Solution {
public:
    bool check(int i , int currSum, string s, int num, vector<vector<int>>& t){

        //base case
        if(i == s.length()){
           return currSum == num;
        }       

        if(currSum > num) return false;
        
        if(t[i][currSum] != -1) return t[i][currSum];
        bool possible = false;

        for(int j = i; j< s.length(); j++){
            string sub = s.substr(i, j-i+1);

            int val = stoi(sub);

            possible = possible || check(j+1, currSum + val, s, num, t);

            if(possible == true) return true;
        }

        return possible;
    }
    int punishmentNumber(int n) {
        int punish = 0;

        for(int num = 1; num <= n; num++){
            int sq = num * num;

            string s = to_string(sq);
            vector<vector<int>> t(s.length(), vector<int>(num+1, -1));
            if(check(0, 0, s, num, t)){
                punish += sq;
            }
        }

        return punish;
        
    }
};