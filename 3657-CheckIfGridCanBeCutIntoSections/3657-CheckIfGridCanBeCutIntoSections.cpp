// Last updated: 02/05/2026, 22:32:50
class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>> intervals){

        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> mergedIntervals;

        for(int i = 0; i < n; i++){

            if(mergedIntervals.empty() || mergedIntervals.back()[1] <= intervals[i][0]){
                mergedIntervals.push_back(intervals[i]);
            }else{

                mergedIntervals.back()[0] = min(mergedIntervals.back()[0], intervals[i][0]);
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
            }
        }

        return mergedIntervals;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        
        int m = rectangles.size();
        vector<vector<int>> horizontalPartitions;
        vector<vector<int>> verticalPartitions;

        // horizontalPartitions.push_back({0, rectangles[0][0]});
        // verticalPartitions.push_back({0, rectangles[0][1]});
        for(int i = 0; i < rectangles.size(); i++){

            int x1 = rectangles[i][0], y1 = rectangles[i][1];
            int x2 = rectangles[i][2], y2 = rectangles[i][3];

            horizontalPartitions.push_back({x1, x2});
            verticalPartitions.push_back({y1, y2});
        }

        // horizontalPartitions.push_back({rectangles[m - 1][2], n});
        // verticalPartitions.push_back({rectangles[m - 1][3], n});

        horizontalPartitions = mergeIntervals(horizontalPartitions);
        verticalPartitions = mergeIntervals(verticalPartitions);

        bool cutsPossible = (horizontalPartitions.size() >= 3) || (verticalPartitions.size() >= 3);

        return cutsPossible;
    }
};