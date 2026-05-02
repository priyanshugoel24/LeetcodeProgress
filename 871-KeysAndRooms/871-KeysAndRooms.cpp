// Last updated: 02/05/2026, 22:42:54
class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& rooms){

        visited[node] = true;

        for(auto &nbr : rooms[node]){

            if(!visited[nbr]){
                dfs(nbr, visited, rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();
       
        vector<int> visited(n, false);

        dfs(0, visited, rooms);

        bool allVisited = all_of(visited.begin(), visited.end(), [](bool val){
            return val;
        });

        return allVisited;
    }
};