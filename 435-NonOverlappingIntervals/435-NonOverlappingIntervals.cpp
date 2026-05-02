// Last updated: 02/05/2026, 22:44:52
class Solution {
public:
   
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        int n = intervals.size(), cnt = 1, max = intervals[0][1];

        for(int i = 1; i<n; i++){

            if( max <= intervals[i][0]){
                cnt++;
                max = intervals[i][1];
            }

        }

        return n - cnt;

        

        
    }
};