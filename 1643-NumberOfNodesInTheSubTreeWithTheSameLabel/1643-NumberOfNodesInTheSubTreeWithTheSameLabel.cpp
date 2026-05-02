// Last updated: 02/05/2026, 22:39:21
class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int curr_node, int parent_node, vector<int>& result, string& labels, vector<int>& count){

        char myLabel = labels[curr_node];

        int count_before_visiting_curr = count[myLabel - 'a'];

        count[myLabel - 'a'] += 1;

        for(int &nbr : adj[curr_node]){

            if(nbr == parent_node){
                continue;
            }

            dfs(adj, nbr, curr_node, result, labels, count);
        }

        int count_after_visiting_curr_children = count[myLabel - 'a'];

        result[curr_node] = count_after_visiting_curr_children - count_before_visiting_curr;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {

        unordered_map<int, vector<int>> adj;

        for(auto &edge : edges){

            int u = edge[0], v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(n, 0);
        vector<int> count(26, 0);

        dfs(adj, 0, -1, result, labels, count);

        return result;
        
    }
};