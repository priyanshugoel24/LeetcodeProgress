// Last updated: 02/05/2026, 22:49:15
class Solution {
public:
    int t[21][21];
    bool solve(int i, int j, string s, string p){
        if(j == p.length()){
            return i == s.length();
        }

        if(t[i][j] != -1) return t[i][j];

        bool firstcharMatched = false;

        if(i < s.length()&& (p[j] == s[i] || (p[j] == '.'))){
            firstcharMatched = true;
        }

        if(p[j+1] == '*'){
            bool not_take = solve(i, j+2, s, p);
            bool take = (firstcharMatched && solve(i+1, j, s, p));

            return t[i][j] =  not_take || take;
        }

        
        return t[i][j] = firstcharMatched && solve(i+1, j+1, s, p);
        
    }
    bool isMatch(string s, string p) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, s, p);
    }
};