// Last updated: 02/05/2026, 22:34:47
class Solution {
public:
    const long long large = 2e9; // Large constant weight to use when setting unused -1 edges
    typedef long long ll;
    typedef pair<long, long> P;

    // Dijkstra function to compute shortest path from source to destination
    ll djikstra(vector<vector<int>>& edges, int n, int source, int destination) {
        
        // Build the adjacency list graph, skipping edges with weight -1
        unordered_map<ll, vector<pair<ll, ll>>> adj;
        for(vector<int>& edge : edges) {
            if(edge[2] != -1) {
                int u = edge[0], v = edge[1], wt = edge[2];
                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }

        // Min-heap to get node with the smallest tentative distance
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<ll> result(n, INT_MAX);  // Store shortest distance to each node
        vector<bool> visited(n, false); // Visited flag for each node

        result[source] = 0;
        pq.push({0, source}); // Start with the source node

        // Dijkstra’s main loop
        while(!pq.empty()) {
            ll currDist = pq.top().first;
            ll currNode = pq.top().second;
            pq.pop();

            if(visited[currNode]) continue;
            visited[currNode] = true;

            // Relax the neighbors
            for(auto& [nbr, wt] : adj[currNode]) {
                if(result[nbr] > currDist + wt) {
                    result[nbr] = currDist + wt;
                    pq.push({result[nbr], nbr});
                }
            }
        }

        return result[destination]; // Return distance to destination
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        
        // Step 1: Check initial shortest path ignoring -1 edges
        ll currShortestDist = djikstra(edges, n, source, destination);

        // If the current shortest path is already less than the target, it's impossible to adjust
        if(currShortestDist < target) {
            return {}; // Not possible
        }

        // If the current path equals the target, set -1 edges to large values and return
        bool matchedTarget = (currShortestDist == target);
        if(matchedTarget) {
            for(vector<int>& edge : edges) {
                if(edge[2] == -1) {
                    edge[2] = large; // Set unused -1 weights to large value so they’re not part of shortest path
                }
            }
            return edges; // Already matched, done
        }

        // Step 2: Try to gradually modify -1 edges to reduce the shortest path to exactly the target
        for(vector<int>& edge : edges) {
            if(edge[2] == -1) {
                edge[2] = (matchedTarget == true) ? large : 1; // Set to smallest possible initially

                if(!matchedTarget) {
                    // Recompute shortest path with new edge weight
                    ll newShortestDist = djikstra(edges, n, source, destination);

                    if(newShortestDist <= target) {
                        matchedTarget = true;
                        // Increase edge weight to exactly match the target distance
                        edge[2] += (target - newShortestDist);
                    }
                }
            }
        }

        // Final check: if after all attempts we still didn’t match target, return empty
        if(!matchedTarget) return {};

        return edges; // Return modified edge list
    }
};
