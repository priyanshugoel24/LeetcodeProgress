// Last updated: 02/05/2026, 22:45:52
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n+1); // nth ugly number

        int i2 = 1, i3 = 1, i5 = 1;

        ugly[1] = 1; // first ugly number

        for(int i = 2; i <= n; i++){
            int i2_num = ugly[i2] * 2;
            int i3_num = ugly[i3] * 3;
            int i5_num = ugly[i5] * 5;

            int minUglynum = min({i2_num, i3_num, i5_num});

            ugly[i] = minUglynum;

            //increment pointer of corresponding ugly number

            if(minUglynum == i2_num){
                i2++;
            }
            if(minUglynum == i3_num){
                i3++;
            }
            if(minUglynum == i5_num){
                i5++;
            }

        }

        return ugly[n];


    }
};