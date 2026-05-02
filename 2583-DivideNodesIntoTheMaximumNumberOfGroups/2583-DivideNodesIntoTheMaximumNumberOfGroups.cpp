// Last updated: 02/05/2026, 22:35:37
class Solution {
public:
    bool isBipartite(unordered_map<int, vector<int>>& adj, int currNode, vector<int>& colours, int currColour){
        colours[currNode] = currColour;

        for(auto &nbr : adj[currNode]){
            if(colours[nbr] == colours[currNode]) return false;

            if(colours[nbr] == -1){
                if(!isBipartite(adj, nbr, colours, 1-currColour)) return false;
            }
        }

        return true;
    }

    int bfs(unordered_map<int, vector<int>>& adj, int node, int n){
        vector<int> visited(n+1, false);

        queue<int> q;
        q.push(node);
        visited[node] = true;

        int level = 1;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int curr = q.front();
                q.pop();

                for(int nbr : adj[curr]){
                    if(visited[nbr]) continue;

                    q.push(nbr);
                    visited[nbr] = true;
                }
            }

            level++; //1 level extra will be added after executing last while loop
        }

        return level-1;
    }

    int maxfromeachComponent(unordered_map<int, vector<int>>& adj, int node, vector<bool>& visited, vector<int>& levels){
        int maxGroups = levels[node];
        visited[node] = true;

        for(auto &nbr : adj[node]){
            if(!visited[nbr]){
                maxGroups = max(maxGroups, maxfromeachComponent(adj, nbr, visited, levels));
            }
        }

        return maxGroups;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;
        for(auto &edge : edges){
            int u = edge[0], v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //Bipartite Check
        vector<int> colours(n+1, -1);
        for(int node = 1; node <=n; node++){
            if(colours[node] == -1){
                if(!isBipartite(adj, node, colours, 1)) return -1;
            }
        }

        //find max levels by starting bfs from each node

        vector<int> levels(n+1, 0);
        for(int node = 1; node <= n ; node++){
            levels[node] = bfs(adj, node, n);
        }

        int maxGroupeachComponent = 0;
        vector<bool> visited(n+1, false);
        for(int node = 1; node <= n ; node++){
            if(!visited[node]) maxGroupeachComponent += maxfromeachComponent(adj, node, visited, levels);
        }

        return maxGroupeachComponent;
        
    }
};