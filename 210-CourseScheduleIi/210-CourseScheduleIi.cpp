// Last updated: 02/05/2026, 22:46:24
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<int> empty;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(const auto&pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        for(int i = 0 ;i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            count++;

            for(int it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        return (count == numCourses) ? result : empty ;
        
        
    }
};