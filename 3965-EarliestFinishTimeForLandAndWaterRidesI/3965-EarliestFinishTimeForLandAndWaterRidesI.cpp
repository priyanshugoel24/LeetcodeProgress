// Last updated: 02/05/2026, 22:32:14
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int minTime = INT_MAX;

        // try from land to water
        for (int i = 0; i < landStartTime.size(); ++i) {
            int landStart = landStartTime[i];
            int landDur = landDuration[i];
            int landFinish = landStart + landDur;

            for (int j = 0; j < waterStartTime.size(); ++j) {
                int waterStart = waterStartTime[j];
                int waterDur = waterDuration[j];
                int startWater = max(landFinish, waterStart);
                int totalFinish = startWater + waterDur;

                minTime = min(minTime, totalFinish);
            }
        }

        // try from water to land
        for (int i = 0; i < waterStartTime.size(); ++i) {
            int waterStart = waterStartTime[i];
            int waterDur = waterDuration[i];
            int waterFinish = waterStart + waterDur;

            for (int j = 0; j < landStartTime.size(); ++j) {
                int landStart = landStartTime[j];
                int landDur = landDuration[j];
                int startLand = max(waterFinish, landStart);
                int totalFinish = startLand + landDur;

                minTime = min(minTime, totalFinish);
            }
        }

        return minTime;
    }
};
