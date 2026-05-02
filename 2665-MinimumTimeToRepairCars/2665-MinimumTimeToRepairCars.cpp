// Last updated: 02/05/2026, 22:35:25
class Solution {
public:
    bool isPossible(vector<int>& ranks, int cars, long long mid){

        long long totalRepairedCars = 0;

        for(auto rank : ranks){

            totalRepairedCars += sqrt(mid/rank);
        }
        return (totalRepairedCars >= cars);
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int worstRank = INT_MIN;

        for(auto rank : ranks){
            worstRank = max(worstRank, rank);
        }

        long long ans = -1;
        long long l = 1, r = (( long long ) worstRank * cars * cars);

        while(l <= r){
            long long mid = l + (r-l)/2;

            if(isPossible(ranks, cars, mid)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;
    }
};