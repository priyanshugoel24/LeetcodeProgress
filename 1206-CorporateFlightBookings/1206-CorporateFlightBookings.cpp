// Last updated: 02/05/2026, 22:41:28
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector<int> diff(n, 0);
        vector<int> ans(n, 0);

        for(int i = 0; i<bookings.size(); i++){
            int first = bookings[i][0], last = bookings[i][1], seats = bookings[i][2];

            if(first-1 >= 0)diff[first-1] += seats;
            if(last < n) diff[last] -= seats;
        }

        //calculate cumSum for diff array

        int cumSum = diff[0];
        for(int i = 1; i<n; i++){
            diff[i] += cumSum;
            cumSum = diff[i];
        }

        return diff;
    }
};