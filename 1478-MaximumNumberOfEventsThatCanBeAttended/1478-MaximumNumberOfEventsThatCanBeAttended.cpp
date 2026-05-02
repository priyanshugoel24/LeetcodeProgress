// Last updated: 02/05/2026, 22:40:06
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        int n = events.size();

        // Find the last day any event ends, so we know the upper bound for looping days
        int last_day = 0;
        for(int i = 0; i < n; i++){
            last_day = max(last_day, events[i][1]);
        }

        // Sort events based on start day (and implicitly end day if start days are same)
        sort(begin(events), end(events));

        // Min-heap to store end days of events available on the current day
        priority_queue<int, vector<int>, greater<>> pq;

        int events_attended = 0;  // Counter for how many events we successfully attend

        int i = 1;  // Start from day 1 (since event days are 1-based)
        int j = 0;  // Pointer to iterate over events

        // Iterate through each day from 1 to last_day
        while(i <= last_day){

            // Add all events that start on or before the current day
            while(j < n && events[j][0] <= i){
                pq.push(events[j][1]);  // Push the event's end day into the min-heap
                j++;
            }

            // Remove events from heap that have already expired (end before today)
            while(!pq.empty() && pq.top() < i){
                pq.pop();
            }

            // Attend the event that ends the earliest (if any available)
            if(!pq.empty()){
                pq.pop();  // Attend the event and remove it from the heap
                events_attended += 1;
            }

            i++;  // Move to the next day
        }

        // Return the maximum number of events attended
        return events_attended;
    }
};
