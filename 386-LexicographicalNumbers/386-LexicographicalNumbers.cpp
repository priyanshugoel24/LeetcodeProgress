// Last updated: 02/05/2026, 22:45:08
class Solution {
public:
    void solve(int currNo, int n, vector<int>& result){
        //base case
        if(currNo > n) return;

        result.push_back(currNo);

        for(int i = 0; i<=9; i++){
            int nextNo = currNo * 10 + i;
            if(nextNo > n) return;
            solve(nextNo, n, result);
        }
    }
    vector<int> lexicalOrder(int n) {

        vector<int> result;

        for(int i = 1; i<= 9; i++){
            if(i > n) break;
            solve(i, n, result);
        }

        return result;
    }
};