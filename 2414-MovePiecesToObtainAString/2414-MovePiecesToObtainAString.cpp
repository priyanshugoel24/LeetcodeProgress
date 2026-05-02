// Last updated: 02/05/2026, 22:36:25
class Solution {
public:
    bool canChange(string start, string target) {

        int n = start.length();

        int i = 0, j = 0;

        while(i < n || j < n){

            while(i < n && start[i] == '_') i++; //ignore the starting whitespaces of string start
            while(j< n && target[j] == '_') j++; //ignore the starting whitespaces of string target

            if(i == n || j == n) return (i == n && j == n); // if one string gets finished the other should be also finished

            if(start[i] != target[j]) return false; // the sequence of characters doesn't match

            if(start[i] == 'L' && i < j) return false; // as L in start won't be able to move right to make correct sequence

            if(start[i] == 'R' && i > j) return false; // as R in start won't be able to move left to make correct sequence;

            i++, j++; // if none of the conditions are violated we can generate the target string
        }

        return true;
        
    }
};