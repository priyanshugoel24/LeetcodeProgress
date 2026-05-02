// Last updated: 02/05/2026, 22:39:16
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> vertices;

        vector<int> indegree(n, 0);

        for(auto& edge : edges){

            int u = edge[0], v = edge[1];
            indegree[v]++;
        }

        for(int i = 0; i < n; i++){
            
            if(indegree[i] == 0){
                vertices.push_back(i);
            }
        }

        return vertices;
    }
};