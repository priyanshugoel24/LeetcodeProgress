// Last updated: 02/05/2026, 22:45:06
class Solution {
public:
    double dfs(string src, string dest, unordered_map<string, vector<pair<string, double>>>& adj, unordered_set<string>& visited) {
        
        if (adj.find(src) == adj.end() || adj.find(dest) == adj.end()) return -1.0;
        if (src == dest) return 1.0;

        visited.insert(src);

        for (auto& [next, weight] : adj[src]) {
            if (visited.find(next) != visited.end()) continue;

            double result = dfs(next, dest, adj, visited);
            if (result != -1.0) {
                return weight * result;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;


        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }

        vector<double> ans;

        for (auto& query : queries) {
            string src = query[0], dest = query[1];

            unordered_set<string> visited;
            double res = dfs(src, dest, adj, visited);

            ans.push_back(res);
        }

        return ans;
    }
};
