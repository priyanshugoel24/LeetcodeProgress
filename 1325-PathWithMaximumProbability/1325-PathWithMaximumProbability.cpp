// Last updated: 02/05/2026, 22:40:56
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<double> maxProb(n, 0.0);

        unordered_map< int, vector<pair<int, double>> > adj;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue< pair<double, int> > pq;
        pq.push({1.0, start_node});

        while(!pq.empty()){

            auto [prob, node] = pq.top();
            pq.pop();

            if(node == end_node){
                return prob;
            }

            for(auto& [nbr, wt] : adj[node]){

                if(prob * wt > maxProb[nbr]){
                    maxProb[nbr] = prob * wt;
                    pq.push({maxProb[nbr], nbr});
                }
            }
        }

        return 0.0;


    }
};