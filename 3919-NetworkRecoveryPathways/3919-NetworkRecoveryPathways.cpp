// Last updated: 02/05/2026, 22:32:19
class Solution {
public:
    
    bool isPossible(int min_score, int n, unordered_map<int, vector<pair<int,int>>>& adj, vector<bool>& online, long long k){

        // initialize distance array with max value
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

       
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while(!pq.empty()){

            auto [cost, node] = pq.top();
            pq.pop();

            // if we already have a shorter path
            if(cost > dist[node]){
                continue;
            }

            for(auto& [nbr, wt] : adj[node]){

                // wt must be at least min_score
                if(wt < min_score){
                    continue;
                }

                // check if it is online (except destination)
                if(nbr != n - 1 && !online[nbr]){
                    continue;
                }

               
                if(dist[nbr] > cost + wt){
                    dist[nbr] = cost + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        // check if we could reach the destination within k
        bool success = dist[n - 1] <= k;
        return success;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size(); // number of nodes from 0 to n - 1

        // building the directed acyclic graph
        unordered_map<int, vector<pair<int, int>>> adj;
        int maxEdgeWt = 0;

        for(auto& edge : edges){
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
            maxEdgeWt = max(maxEdgeWt, wt);
        }

        int max_path_score = -1;

        // binary search over possible minimum edge score
        int l = 0, r = maxEdgeWt;

        while(l <= r){

            int mid = l + (r - l ) / 2;

            if(isPossible(mid, n, adj, online, k)){
                max_path_score = mid; 
                l = mid + 1;         
            } else {
                r = mid - 1;         
            }
        }

        return max_path_score;
    }
};
