// Last updated: 02/05/2026, 22:32:45
class Solution {
public:

    bool isPossible(int val, unordered_map<int, vector<pair<int, int> > >& adj, int n){

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        
        while(!q.empty()){

            int curr = q.front();
            q.pop();

            visited[curr] = true;

            for(auto& [nbr, wt] : adj[curr]){

                if(wt > val) continue;
                
                if(!visited[nbr]){
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }

        for(int i = 0; i < n; i++){

            if(visited[i] == false) return false;
        }

        return true;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        
        unordered_map<int, vector<pair<int, int> > > adj;

        int minEdgeWt = INT_MAX, maxEdgeWt = INT_MIN;
        //build a reversed graph
        for(auto& edge : edges){

            int u = edge[0], v = edge[1], wt = edge[2];

            minEdgeWt = min(minEdgeWt, wt);
            maxEdgeWt = max(maxEdgeWt, wt);
            adj[v].push_back({u, wt});
        }

        int l = minEdgeWt, r = maxEdgeWt;

        int minWt = -1;
        while(l <= r){

            int mid = l + (r - l) / 2;

            if(isPossible(mid, adj, n)){
                minWt = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return minWt;

    }
};