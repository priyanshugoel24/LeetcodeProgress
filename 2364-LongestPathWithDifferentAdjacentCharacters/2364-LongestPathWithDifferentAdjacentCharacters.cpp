// Last updated: 02/05/2026, 22:36:39
class Solution {
public:
    int length = 0;
    int dfs(int curr_node, int parent_node, unordered_map<int, vector<int>>& adj, string& s){

        int longest_path = 0, second_longest_path = 0;

        for(auto &nbr : adj[curr_node]){

            if(nbr == parent_node) continue;

            int longest_path_from_child = dfs(nbr, curr_node, adj, s);

            if(s[nbr] == s[curr_node]){
                continue;
            }

            if(longest_path_from_child > second_longest_path){
                second_longest_path = longest_path_from_child;
            }

            if(second_longest_path > longest_path){
                swap(longest_path, second_longest_path);
            }
        }

        int answer_for_curr = 1 + longest_path + second_longest_path;
        length = max(length, answer_for_curr);

        int return_call_for_curr = 1 + max(longest_path, second_longest_path);

        return return_call_for_curr;
    }
    int longestPath(vector<int>& parent, string s) {

        int n = parent.size();

        unordered_map<int, vector<int>> adj;
        
        for(int i = 0; i < n; i++){
            
            int u = i;
            int v = parent[i];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        dfs(0, -1, adj, s);

        return length;
    }
};