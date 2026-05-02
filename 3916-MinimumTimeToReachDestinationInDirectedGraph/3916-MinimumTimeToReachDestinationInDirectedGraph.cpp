// Last updated: 02/05/2026, 22:32:22
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<tuple<int, int, int>>> adj;
        // node -> {nbr, startTime, endTime}

        // building the graph
        for(auto& edge : edges){

            int u = edge[0], v = edge[1], startTime = edge[2], endTime = edge[3];

            adj[u].push_back({v, startTime, endTime});
        }

        // min time it would take to reach each node
        vector<int> minTimeToReach(n, INT_MAX);
        minTimeToReach[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // {time, node}
        pq.push({0, 0});

        while(!pq.empty()){

            auto [currTime, node] = pq.top();
            pq.pop();

            // traverse edges of the node
            for(auto& [nbr, startTime, endTime] : adj[node]){
                
                // if curr time is already greater than what was possible to traverse the nbr, continue to next edge
                if(currTime > endTime){
                    continue;
                }
                // if graph contains self loops
                if(nbr == node){
                    continue;
                }

               

                // new time to reach nbr will be starting time possible to traverse that edge plus 1 second for time to travel the edge
                int waitTime = max(currTime, startTime);
                int newTimeToReachNbr = waitTime + 1;

                // if the new time to reach nbr is less than what is already stored, update this time to the min value
                if(newTimeToReachNbr < minTimeToReach[nbr]){
                    minTimeToReach[nbr] = newTimeToReachNbr;

                    // push the nbr with updated time
                    pq.push({newTimeToReachNbr, nbr});
                }
            }
        }

        // if time to reach last node i.e n - 1 is int_max means it is not possible to reach that node otherwise return the min time possible
        int timeToReachLastNode = (minTimeToReach[n - 1] == INT_MAX ? -1 : minTimeToReach[n - 1]);

        return timeToReachLastNode;
    }
};