// Last updated: 02/05/2026, 22:43:12
class Solution {
public:
    void dfs(int node, int destination, vector<int>& path,
             vector<vector<int>>& allPaths, vector<vector<int>>& graph) {

        if (node == destination) {
            allPaths.push_back(path);
            return;
        }

        for (auto& nbr : graph[node]) {

            path.push_back(nbr);
            dfs(nbr, destination, path, allPaths, graph);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int n = graph.size(); // no of vertices in graph

        int src = 0;      // source vertex
        int dest = n - 1; // destination vertex

        vector<vector<int>> allPaths; // all paths from source to vertex
        vector<int> path;             // current path
        path.push_back(src);

        dfs(src, dest, path, allPaths, graph);

        return allPaths;
    }
};