// Last updated: 02/05/2026, 22:39:38
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
       unordered_map<int, vector<int>> adj;

       vector<int> indegree(numCourses, 0);

       for(auto pre : prerequisites){
        int u = pre[0], v = pre[1];
        adj[u].push_back(v);
        indegree[v]++;
       } 

       queue<int> q;
       for(int i = 0; i<numCourses; i++){
        if(indegree[i] == 0) q.push(i);
       }

       int Q = queries.size();
       vector<bool> result(Q, false);

       unordered_map<int, unordered_set<int>> mp;

       while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto nbr : adj[front]){

            mp[nbr].insert(front);
            for(auto preq : mp[front]) mp[nbr].insert(preq);

        
            indegree[nbr]--;
            if(indegree[nbr] == 0) q.push(nbr);
        }
       }

       for(int i = 0; i<Q; i++){
        int src = queries[i][0], dest = queries[i][1];

        bool reachable = mp[dest].contains(src);
        result[i] = reachable;
       }

       return result;
       


    }
};