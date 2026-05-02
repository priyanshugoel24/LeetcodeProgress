// Last updated: 02/05/2026, 22:38:38
class Solution {
public:
    int findNextValidIdx(vector<vector<int>>& events, int currEnd, int startIdx){

        int left = startIdx, right = events.size();

        while(left < right){
            int mid = (left + right) / 2;
            if(events[mid][0] > currEnd){
                right = mid;
            }else{
                left = mid + 1;
            }
        }

        return left;
    }
    int solve(int idx, vector<vector<int>>& events, int k, vector<vector<int>>& dp) {

        // base case
        if (idx >= events.size() || k == 0) {
            return 0;
        }

        //if subproblem is already solved
        if(dp[idx][k] != -1){
            return dp[idx][k];
        }

        // attend event
        int nextIdx = findNextValidIdx(events, events[idx][1], idx + 1);
        int attend = events[idx][2] + solve(nextIdx, events, k - 1, dp);

        // skip event
        int notAttend = 0 + solve(idx + 1, events, k, dp);

        return dp[idx][k] = max(attend, notAttend);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        sort(events.begin(), events.end(),
             [](auto& a, auto& b) { return a[0] < b[0]; });

        return solve(0, events, k, dp);
    }
};