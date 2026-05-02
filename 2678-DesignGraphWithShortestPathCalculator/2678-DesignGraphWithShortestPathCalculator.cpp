// Last updated: 02/05/2026, 22:35:21
class Graph {
public:
    vector<vector<pair<int, int>>> adjList;
    Graph(int n, vector<vector<int>>& edges) {
        adjList.resize(n);

        for(auto& edge : edges){

            int u = edge[0], v = edge[1], cost = edge[2];

            adjList[u].push_back({v, cost});
        }
    }
    
    void addEdge(vector<int> edge) {
        
        int u = edge[0], v = edge[1], cost = edge[2];

        adjList[u].push_back({v, cost});
    }
    
    int shortestPath(int node1, int node2) {
        
        int n = adjList.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> cost(n, INT_MAX);
        cost[node1] = 0;
        pq.push({0, node1});

        while(!pq.empty()){

            int curr_cost = pq.top()[0];
            int curr_node = pq.top()[1];
            pq.pop();

            if(curr_cost > cost[curr_node]){
                continue;
            }

            if(curr_node == node2){
                return curr_cost;
            }

            for(auto& nbr : adjList[curr_node]){
                int nbr_node = nbr.first;
                int nbr_cost = nbr.second;
                
                if(nbr_cost + curr_cost < cost[nbr_node]){
                    cost[nbr_node] = curr_cost + nbr_cost;
                    pq.push({cost[nbr_node], nbr_node});
                }
            }

           
        }

        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */