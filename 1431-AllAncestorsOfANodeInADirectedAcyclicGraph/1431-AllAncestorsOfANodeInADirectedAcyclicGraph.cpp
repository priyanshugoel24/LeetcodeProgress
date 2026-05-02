// Last updated: 02/05/2026, 22:40:23
class Solution {
public:
    vector<int> dfs(int node, unordered_map<int, vector<int>>& reversedGraph, unordered_map<int, vector<int>>& dp) {

        if (dp.count(node)) return dp[node];

        set<int> parents;

        for (auto& nbr : reversedGraph[node]) {
            parents.insert(nbr);

            vector<int> rest = dfs(nbr, reversedGraph, dp);
            for (int x : rest) {
                parents.insert(x);
            }
        }

        vector<int> all_parents(parents.begin(), parents.end());
        return dp[node] = all_parents;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> reversedGraph;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            reversedGraph[v].push_back(u);
        }

        unordered_map<int, vector<int>> dp;
        vector<vector<int>> ancestors(n);

        for (int i = 0; i < n; i++) {
            ancestors[i] = dfs(i, reversedGraph, dp);
        }

        return ancestors;
    }
};
