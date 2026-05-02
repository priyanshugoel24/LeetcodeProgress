// Last updated: 02/05/2026, 22:33:00
class Solution {
public:
    int bfs(int curr, unordered_map<int, vector<int>>& adj, int d, int n){

        queue<pair<int, int>> q;
        q.push({curr, 0});

        vector<bool> visited(n, false);
        visited[curr] = true;

        int count = 0;

        while(!q.empty()){

            int currNode = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(dist > d){
                continue;
            }

            count++;

            for(auto &nbr : adj[currNode]){

                if(!visited[nbr]){
                    visited[nbr] = true;
                    q.push({nbr, dist + 1});
                }
            }
        }

        return count;
    }
    vector<int> findCount(vector<vector<int>>& edges, int d){

        int n = edges.size() + 1;

        unordered_map<int, vector<int>> adj;

        for(auto &edge : edges){

            int u = edge[0], v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(n);

        for(int i = 0; i < n; i++){

            result[i] = bfs(i, adj, d, n);
            
        }

        return result;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {

        int n = edges1.size() + 1;

        vector<int> targetNodes1 = findCount(edges1, k);
        // target nodes in tree1 within k dist

        vector<int> targetNodes2 = findCount(edges2, k - 1);
        //target nodes in tree2 within k-1 dist

        int maxTargetNodesCount = *max_element(targetNodes2.begin(), targetNodes2.end());

        for(int i = 0; i < targetNodes1.size(); i++){
            
            targetNodes1[i] += maxTargetNodesCount;
        }

        return targetNodes1;
        
    }
};