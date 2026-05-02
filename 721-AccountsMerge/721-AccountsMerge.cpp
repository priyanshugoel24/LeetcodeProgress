// Last updated: 02/05/2026, 22:43:40
class DisjointSet {
    
public:
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            
        }
    }

    int findUPar(int x) {
        if (parent[x] != x) {
            parent[x] = findUPar(parent[x]);
        }
        return parent[x];
    }

    void unionbyRank(int x, int y) {
        int rootx = findUPar(x);
        int rooty = findUPar(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                parent[rootx] = rooty;
            } else if (rank[rootx] > rank[rooty]) {
                parent[rooty] = rootx;
            } else {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        DisjointSet ds(accounts.size());

        int n = accounts.size();
        unordered_map<string, int> mapMailNode;
        for(int i = 0; i<n; i++){
            for(int j = 1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];

                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }
                else{
                    ds.unionbyRank(i, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];

        for(auto it : mapMailNode){
            string mail = it.first;
            int node = ds.findUPar(it.second);

            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i = 0; i<n; i++){
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(auto it : mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
        
    }
};