// Last updated: 02/05/2026, 22:40:50
class Solution {
public:
    bool canDistribute(vector<int>& candies, long long k, int mid){

        long long childrenCount = 0;
        for(int i = 0; i<candies.size(); i++){
            childrenCount += candies[i]/ mid;
        }

        return (childrenCount >= k);
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int maxCandies = 0;
        for(auto candy : candies){
            maxCandies = max(maxCandies, candy);
        }
        int ans = -1;

        int l = 1, r = maxCandies;

        while(l <= r){

            int mid = l + (r-l)/2;

            if(canDistribute(candies, k, mid)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return (ans == -1) ? 0 : ans;
    }
};