// Last updated: 02/05/2026, 22:33:40
class Solution {
public:
    vector<int> djikstra(unordered_map<int, vector<pair<int, int>>>& adj, int src, int target){
        
        vector<int> dist(src + target + 1, INT_MAX);
        set<pair<int, int> > st;
        dist[src] = 0;
        st.insert({0, src});

        vector<bool> visited(src + target + 1, false);

        while(!st.empty()){

            auto [node_wt, node] = *(st.begin());
            st.erase(st.begin());
            

            if(visited[node] == true){
                continue;
            }

            for(auto& [nbr_node, nbr_wt] : adj[node]){

                if(dist[nbr_node] > nbr_wt + node_wt){

                    if(st.find({dist[nbr_node], nbr_node}) != st.end()){
                        st.erase({dist[nbr_node], nbr_node});
                    }

                    dist[nbr_node] = nbr_wt + node_wt;

                    st.insert({dist[nbr_node], nbr_node});
                }
            }

            visited[node] = true;
        }

        return dist;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        
        vector<bool> result(edges.size(), false);

        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto& edge : edges){

            int u = edge[0], v= edge[1], dist = edge[2];

            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }

        vector<int> dist_from_src = djikstra(adj, 0, n - 1);
        vector<int> dist_from_target = djikstra(adj, n - 1, 0);

        int shortest_dist = dist_from_src[ n - 1];

        for(int i = 0; i < edges.size(); i++){

            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];

            if(dist_from_src[u] == INT_MAX || dist_from_target[v] == INT_MAX || dist_from_src[v] == INT_MAX || dist_from_target[u] == INT_MAX){
                continue;
            }
            
            if(dist_from_src[u] + wt + dist_from_target[v] == shortest_dist){
                result[i] = true;
            }

            if(dist_from_src[v] + wt + dist_from_target[u] == shortest_dist){
                result[i] = true;
            }
        }

        return result;
    }
};