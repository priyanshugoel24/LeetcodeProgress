// Last updated: 02/05/2026, 22:48:28
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> mergedIntervals;

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        for(int i = 0; i < n; i++){

            // if it is the first interval or the new interval is non-overlapping, push this interval to result 
            if(mergedIntervals.empty() || intervals[i][0] > mergedIntervals.back()[1]){
                mergedIntervals.push_back(intervals[i]);
            }else{
                // it is an overlapping interval, so we need to udpate the end of current merged intervals to include the overlapping interval

                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
                mergedIntervals.back()[0] = min(mergedIntervals.back()[0], intervals[i][0]);
            }
        }

        return mergedIntervals;
    }
};