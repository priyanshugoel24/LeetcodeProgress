// Last updated: 02/05/2026, 22:39:32
class Solution {
public:
    int dfs(int curr_node, int parent_node, unordered_map<int, vector< pair<int, int> > > &adj){

        int count = 0;

        for(auto& child : adj[curr_node]){

            int nbr = child.first;
            int direction = child.second;

            if(nbr != parent_node){

                count += direction;
                
                count += dfs(nbr, curr_node, adj);
            }
        }

        return count;
    }
    int minReorder(int n, vector<vector<int>>& connections) {


        unordered_map<int, vector< pair<int, int> > > adj;
        // node -> {child, direction}
        
        for(auto& connection : connections){

            int u = connection[0], v = connection[1];

            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        int min_edges_to_change = dfs(0, -1, adj);

        return min_edges_to_change;
        
    }
};