// Last updated: 02/05/2026, 22:37:31
class Solution {
public:
    int searchValidEvent(vector<vector<int>>& events, int endtime){

        //binary search to find valid event

        int l = 0, r = events.size()-1;
        int result = events.size();

        while(l <= r){
            int mid = l + (r-l)/2;

            if(events[mid][0] > endtime){
                result= mid;
                r = mid-1;
            } else{
                l = mid +1;
            }
        }

        return result;
    }
    int solve(vector<vector<int>>& events, int index, int count, vector<vector<int>>& dp){
        
        int n = events.size();

        
        if(count == 2 || index >= n){
            dp[index][count] = 0;
        }
         
        if(dp[index][count] != -1) return dp[index][count];

        int nextValidIndex = searchValidEvent(events, events[index][1]);

        int attend = events[index][2] + solve(events, nextValidIndex, count+1, dp);
        int notAttend = 0 + solve(events, index+1, count, dp);

        return dp[index][count] = max(attend, notAttend);

    }
    int maxTwoEvents(vector<vector<int>>& events) {

        int n = events.size();
        sort(events.begin(), events.end()); //based on their starting time
        
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        int count = 0;
        return solve(events,0,count, dp);


        
    }
};