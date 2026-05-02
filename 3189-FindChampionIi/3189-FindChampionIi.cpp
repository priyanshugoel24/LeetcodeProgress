// Last updated: 02/05/2026, 22:34:16
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<int> indegree(n, 0);

        for(int i = 0; i < edges.size(); i++){
            indegree[edges[i][1]]++;
        }

        int no_of_champions = 0;
        int unique_champion = -1;

        for(int i = 0; i < n; i++){

            if(indegree[i] == 0){
                unique_champion = i;
                no_of_champions++;
            }
        }

        if(no_of_champions != 1){
            return -1;
        }

        return unique_champion;
    }
};