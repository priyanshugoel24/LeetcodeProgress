// Last updated: 02/05/2026, 22:43:57
class Solution {
public:
    void check(string& s, int i, int j, int n, int& count){
        while(i >= 0 && j < n && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
    }
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for(int i = 0; i<n; i++){

            check(s, i, i, n, count);
            check(s, i, i+1, n, count);
        }

        return count;

    }
};