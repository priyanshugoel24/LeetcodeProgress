// Last updated: 02/05/2026, 22:33:10
class Solution {
public:
    int solve(int n, long long k, vector<int>& operations){

        //base case
        if(n == 0){
            return 0;
        }

        int increments = 0;

        //check k is in which half
        long long mid = pow(2, n-1);

        if(k <= mid){ // in first half
            increments  = 0 + solve(n-1, k, operations);
        }else{ // in second half

            if(operations[n-1] == 1){
                increments = 1 + solve(n-1, k-mid, operations);
            }
            else{
                increments = 0 + solve(n-1, k-mid, operations);
            }
        }

        return increments;
    }
    char kthCharacter(long long k, vector<int>& operations) {
        
        int n = 1;

        while(k >= pow(2, n)){
            n++;
        }
        int noofIncrements = solve(n, k, operations);

        char kthChar = 'a' + (noofIncrements % 26);

        return kthChar;
    }
};