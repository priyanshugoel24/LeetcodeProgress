// Last updated: 02/05/2026, 22:48:19
class Solution {
public:
    int mySqrt(int x) {

        int start = 0;
        int end = x;
        int ans = -1;

        long long int mid = start + (end-start)/2;

        while(start <= end){

            long long int square = mid*mid;

            if(square == x){
                return mid;
            }
            else if(square < x){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }

            mid = start + (end-start)/2;
        }

        return ans;


        
    }
};