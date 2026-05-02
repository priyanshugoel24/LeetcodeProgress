// Last updated: 02/05/2026, 22:43:18
class Solution {
public:
    bool dfs(int node, int V, int col, vector<vector<int>>& graph, vector<int>& color){
        color[node] = col;

        for(auto nbr : graph[node]){
            if(color[nbr] == -1){
                if(!dfs(nbr, V, !col, graph, color)) return false;                
            }
            else if(color[nbr] == color[node]){
                return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v);
        for(int i = 0; i<v; i++) color[i] = -1;

        for(int i = 0; i<v; i++){
            if(color[i] == -1){
                if(!dfs(i, v, 0, graph, color)) return false;
            }
        }

        return true;


        
    }
};