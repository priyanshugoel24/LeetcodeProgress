// Last updated: 02/05/2026, 22:37:21
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        //step 1 : build adjacency list - graph
        unordered_map<int, vector<int>> adj;

        //step 2 : build indegree and outdegree
        unordered_map<int, int> indegree, outdegree;
        //key - node
        //value - indegree/outdegree

        for(auto &edge : pairs){

            int u = edge[0], v = edge[1];

            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }

        //step 3 : find the starting point of the Euler Path
        int startNode = pairs[0][0];
        for(auto &it : adj){

            int node = it.first;
            if(outdegree[node] - indegree[node] == 1){
                startNode = node;
                break;
            }
        }

        //step 4: do dfs traversal
        vector<int> EulerPath;
        stack<int> st;
        st.push(startNode);

        while(!st.empty()){

            int curr = st.top();
            if(!adj[curr].empty()){
                int nbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(nbr);

            }else{
                EulerPath.push_back(curr);
                st.pop();
            }
        }

        // build the euler path
        reverse(begin(EulerPath), end(EulerPath));
        vector<vector<int>> result;

        for(int i = 0; i < EulerPath.size() - 1; i++){
            result.push_back({EulerPath[i], EulerPath[i + 1]});
        }

        return result;
    }
};