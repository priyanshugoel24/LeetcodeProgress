// Last updated: 02/05/2026, 22:41:51
class Solution {
public:
    char dfs(unordered_map<char, vector<char>>& adj, char curr_ch, vector<bool>& visited){

        visited[curr_ch - 'a'] = true;

        char minChar = curr_ch;

        for(char &v : adj[curr_ch]){

            if(!visited[v - 'a']){
                minChar = min(minChar, dfs(adj, v, visited));
            }
        }

        return minChar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        int n = s1.length();

        int m = baseStr.length();

        unordered_map<char, vector<char>> adj;

        for(int i = 0; i < n; i++){

            int u = s1[i];
            int v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string result;

        for(int i = 0; i < m; i++){

            char ch = baseStr[i];

            vector<bool> visited(26, false);

            char minChar = dfs(adj, ch, visited);

            result.push_back(minChar);
        }

        return result;
    }
};