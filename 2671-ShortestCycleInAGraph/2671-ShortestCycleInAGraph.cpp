// Last updated: 02/05/2026, 22:35:24
class Solution {
public:
int ans=INT_MAX;
void cycle(int node,vector<int>adj[],int n,vector<bool>&vis,vector<int>&dis){
    queue<pair<int,int>>q;
    q.push({node,-1});
    vis[node]=true;
    dis[node]=0;
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto it:adj[node]){
            if(dis[it]==1e9){
                 dis[it]=1+dis[node];
                q.push({it,node});
            }
            else if(parent!=it){
                 ans=min(ans,dis[it]+dis[node]+1);
                
            }
        }
    }
    // return false;

}
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int>adj[n+1];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        bool flag=false;
        for(int i=0;i<n;i++){
            vector<int>dis(n+1,1e9);
            vector<bool>vis(n+1,false);
            cycle(i,adj,n,vis,dis);
            
        }
        if(ans==INT_MAX)
        return -1;
        return ans;

    }
};