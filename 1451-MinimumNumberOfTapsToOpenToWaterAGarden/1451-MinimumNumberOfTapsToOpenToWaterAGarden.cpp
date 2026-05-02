// Last updated: 02/05/2026, 22:40:16
class Solution {
public:
    int solve(int idx, int lastPoint,int n, vector<pair<int, int>>& range, map<pair<int,int>, int>& dp){

        //base case : index out of bound
        if(idx >= range.size()){

            //if whole garden is watered
            if(lastPoint >= n){
                return 0;
            }
            
            //else it is not possible to water the whole garden
            return 1e9;
        }

        //if subproblem is already solved
       if(dp.find({idx, lastPoint}) != dp.end()){
        return dp[{idx, lastPoint}];
       }

        //base case : space is left between taps
        if(range[idx].first > lastPoint){
            return 1e9;
        }       

        // option1 : don't open the current tap
        int not_open_tap = solve(idx + 1, lastPoint, n, range, dp);

        // option2 : open the current tap
        int new_lastPoint = max(lastPoint, range[idx].second);
        int open_tap = 1 + solve(idx + 1, new_lastPoint, n, range, dp);

        //memoize the result
        return dp[{idx, lastPoint}] = min(not_open_tap, open_tap);

    }
    int minTaps(int n, vector<int>& ranges) {

        vector<pair<int,int>> range; // range[i] is what portion the tap covers
        

        for(int i = 0; i < ranges.size(); i++){

            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);

            range.push_back({start, end});
        }

        sort(begin(range), end(range));

        int range_size = range.size();

        map<pair<int,int>, int> dp; //memoization map

        int minTapsRequired = solve(0, 0, n,range, dp);

        if(minTapsRequired == 1e9){
            //it is not possible to water the whole garden
            return -1;
        }

        return minTapsRequired;
    }
};