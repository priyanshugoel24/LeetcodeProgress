// Last updated: 02/05/2026, 22:32:40
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {

        int n = startTime.size();

        vector<int> gaps; // gaps in timeline

        int startingGap = startTime[0];

        gaps.push_back(startingGap);

        for (int i = 1; i < n; i++) {

            int gap = startTime[i] - endTime[i - 1];

            gaps.push_back(gap);
        }

        int endingGap = eventTime - endTime[n - 1];

        gaps.push_back(endingGap);

        int left = 0, right = 0;

        int maxPossibleFreeTime = 0;
        int currFreeTime = 0;

        while (right < gaps.size()) {

            currFreeTime += gaps[right];

            if (left < gaps.size() && right - left + 1 > k + 1) {

                currFreeTime -= gaps[left];
                left++;
            }

            maxPossibleFreeTime = max(maxPossibleFreeTime, currFreeTime);
            right++;
        }

        return maxPossibleFreeTime;
    }
};