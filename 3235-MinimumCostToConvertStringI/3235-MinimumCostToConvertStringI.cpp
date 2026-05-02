// Last updated: 02/05/2026, 22:34:06
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int INF = 1e9;
        vector<vector<int>> dist(26, vector<int>(26, INF));

        // Self-loops are zero
        for (int i = 0; i < 26; i++) dist[i][i] = 0;

        // Add initial edges
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]); // In case of multiple edges
        }

        // Floyd-Warshall all-pairs shortest path
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long total_cost_required = 0;
        for (int i = 0; i < source.size(); i++) {
            char s = source[i];
            char t = target[i];

            if (s == t) continue;

            int d = dist[s - 'a'][t - 'a'];
            if (d == INF) return -1;

            total_cost_required += d;
        }

        return total_cost_required;
    }
};
