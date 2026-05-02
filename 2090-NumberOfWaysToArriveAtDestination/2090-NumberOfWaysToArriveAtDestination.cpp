// Last updated: 02/05/2026, 22:37:49
class Solution {
public:
    typedef pair<long long,int> P;
    int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, vector<pair<int,int>>> adj;

        for(auto &road : roads){
            int u = road[0], v = road[1], time = road[2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long> result(n, LLONG_MAX);
        vector<int> pathCount(n, 0);

        result[0] = 0;
        pathCount[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()){
            long long currTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for(auto &vec : adj[currNode]){
                int nbr = vec.first;
                int roadTime = vec.second;

                if(currTime + roadTime < result[nbr]){
                    result[nbr] = currTime + roadTime;
                    pq.push({result[nbr], nbr});
                    pathCount[nbr] = pathCount[currNode];
                }else if(currTime + roadTime == result[nbr]){
                    pathCount[nbr] = (pathCount[nbr] + pathCount[currNode]) % M;
                }
            }
        }

        return pathCount[n-1];
    }
};