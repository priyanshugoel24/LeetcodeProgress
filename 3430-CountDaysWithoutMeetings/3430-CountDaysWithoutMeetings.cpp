// Last updated: 02/05/2026, 22:33:33
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<vector<int>> mergedMeetings;

        for(auto &meeting : meetings){
            if(mergedMeetings.empty() || meeting[0] > mergedMeetings.back()[1]){
                mergedMeetings.push_back(meeting);
            }else{
                mergedMeetings.back()[1] = max(mergedMeetings.back()[1], meeting[1]);
            }
        }

        int meetingDays = 0;

        for(auto &m : mergedMeetings){
            meetingDays += (m[1] - m[0] + 1);
        }

        return days - meetingDays;
    }
};