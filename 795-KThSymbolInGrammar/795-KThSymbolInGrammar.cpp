// Last updated: 02/05/2026, 22:43:21
class Solution {
public:
    int solve(int n, int k){
        //base case
        if(n == 0) return 0;
        if(n == 1 && k == 1) return 0;
        if(n == 1 && k == 2) return 1;

        int length = pow(2, n-1);
        int mid = length/2;

        if(k <= mid){
            return solve(n-1, k);
        }else{
            return 1 - solve(n-1, k-mid);
        }

    }
    int kthGrammar(int n, int k) {
        
        return solve(n, k);
    }
};