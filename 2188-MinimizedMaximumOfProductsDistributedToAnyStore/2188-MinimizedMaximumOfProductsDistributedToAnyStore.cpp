// Last updated: 02/05/2026, 22:37:22
class Solution {
public:
    static bool f(int x, vector<int>& quantities, int n){
        int sum = 0;
        for(int a : quantities){
            sum += (a + x-1) /x;
            
        }

        return sum > n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {

        int left = 1, right = 100000, mid;

        while(left < right){
            mid = left + (right-left)/2;
            if(f(mid, quantities, n)) left = mid+1;
            else right = mid;
        }

        return left;

        
        
    }
};