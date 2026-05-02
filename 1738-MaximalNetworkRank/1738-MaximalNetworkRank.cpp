// Last updated: 02/05/2026, 22:38:58
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int> degree(n);
        set< pair<int, int> > st;
        for(int i = 0; i < roads.size(); i++){
            
            int u = roads[i][0];
            int v = roads[i][1];
            degree[u]++;
            degree[v]++;

            st.insert({u, v});
            st.insert({v, u});
        }

        int networkRank = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){

                int curr_rank = degree[i] + degree[j];
                if(st.find({i, j}) != st.end()){
                    curr_rank--;
                }

                networkRank = max(networkRank, curr_rank);
            }   
        }

        return networkRank;        


    }
};