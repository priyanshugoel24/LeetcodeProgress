// Last updated: 02/05/2026, 22:37:16
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto& meeting : meetings){
            int p1 = meeting[0], p2 = meeting[1], time = meeting[2];
            adj[p1].push_back({p2, time});
            adj[p2].push_back({p1, time});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});

        vector<int> timeToKnowSecret(n, INT_MAX);
        timeToKnowSecret[0] = 0;
        timeToKnowSecret[firstPerson] = 0;

        while(!pq.empty()){
            auto [time, person] = pq.top();
            pq.pop();

            if (time > timeToKnowSecret[person]) continue;

            for(auto& nbr : adj[person]){
                int nextPerson = nbr.first;
                int meet_time = nbr.second;

                if(meet_time >= time && timeToKnowSecret[nextPerson] > meet_time){
                    timeToKnowSecret[nextPerson] = meet_time;
                    pq.push({meet_time, nextPerson});
                }
            }
        }

        vector<int> result;
        for(int i = 0; i < n; i++){
            if(timeToKnowSecret[i] != INT_MAX){
                result.push_back(i);
            }
        }

        return result;
    }
};
