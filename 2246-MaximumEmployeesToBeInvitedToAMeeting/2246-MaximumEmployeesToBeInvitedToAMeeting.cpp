// Last updated: 02/05/2026, 22:37:04
class Solution {
public:
    int BFS(int start, unordered_map<int, vector<int>>& adj, vector<bool>& visited){
        queue<pair<int,int>> q; // {node, pathlength};
        q.push({start, 0});
        int maxDist = 0;

        while(!q.empty()){
            auto [currNode, dist] = q.front();
            q.pop();


            for(auto &nbr : adj[currNode]){
                if(visited[nbr] == false){
                    visited[nbr] = true;
                    q.push({nbr, dist+1});
                    maxDist = max(maxDist, dist+1);
                }
            }
        }

        return maxDist;
    }
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int, vector<int>> adj; // adjacency list for graph

        for(int i = 0; i<n; i++){ // making a graph
            int u = i;
            int v = favorite[i];

            adj[v].push_back(u); // reverse the graph so we can find the path length after traversal
        }

        int longestCycle = 0;
        int happyCouple = 0; // path forming by cycle of length 2 

        vector<bool> vis(n, false);

        for(int i = 0; i<n; i++){
            if(!vis[i]){
                //{node, nodeCount};
                unordered_map<int, int> cnt;

                int currNode = i;
                int currNodeCount = 0;

                while(!vis[currNode]){ //until cycle is not detected
                    vis[currNode] = true;
                    cnt[currNode] = currNodeCount;

                    int nextNode = favorite[currNode]; // favorite node of current node
                    currNodeCount += 1;

                    if(cnt.count(nextNode)){// node is already present in map, so cycle is detected
                        int cycleLength = currNodeCount - cnt[nextNode];

                        longestCycle = max(cycleLength, longestCycle);

                        if(cycleLength == 2){ // happy couple case
                            // currNode <-> nextNode
                            vector<bool> visitedNodes(n, false);
                            visitedNodes[currNode] = true;
                            visitedNodes[nextNode] = true;
                            happyCouple += 2 + BFS(currNode, adj, visitedNodes) + BFS(nextNode, adj, visitedNodes);
                        }
                        break;
                    } 

                    currNode = nextNode;

                }

                
            }

        }

        return max(happyCouple, longestCycle);


        
    }
};