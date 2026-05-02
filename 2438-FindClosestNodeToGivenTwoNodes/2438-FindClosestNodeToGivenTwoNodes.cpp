// Last updated: 02/05/2026, 22:36:19
class Solution {
public:
    vector<int> bfs(int node, vector<int>& edges){

        int n = edges.size();

        queue<int> q;
        vector<int> dist(n, -1); 
        vector<bool> visited(n, false);

        q.push(node);
        visited[node] = true;
        dist[node] = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            int nbr = edges[curr];
            if(nbr != -1 && !visited[nbr]){
                visited[nbr] = true;
                dist[nbr] = dist[curr] + 1;
                q.push(nbr);
            }
        }

        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> dist1 = bfs(node1, edges);
        vector<int> dist2 = bfs(node2, edges);

        int minDist = INT_MAX;
        int closestNode = -1;

        for(int i = 0; i < n; i++){

            if(dist1[i] != -1 && dist2[i] != -1){

                int maxDist = max(dist1[i], dist2[i]);

                if(maxDist < minDist){
                    
                    minDist = maxDist;
                    closestNode = i;
                }
            }
        }

        return closestNode;
    }
};
