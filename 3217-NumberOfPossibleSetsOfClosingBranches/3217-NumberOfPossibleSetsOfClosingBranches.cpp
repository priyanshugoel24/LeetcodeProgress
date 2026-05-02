// Last updated: 02/05/2026, 22:34:10
class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        
        int result = 0;

        for(int set = 0; set < pow(2, n); set++){

            vector<vector<int>> grid(n, vector<int>(n, 1e9));
            for(auto& it : roads){
                int u = it[0], v = it[1], wt = it[2];

                if(((set >> u) & 1) && ((set >> v) & 1)){
                    grid[u][v] = min(grid[u][v], wt);
                    grid[v][u] = min(grid[u][v], wt);
                }
            }

            for(int i = 0; i < n ; i++) grid[i][i] = 0;

            for(int via = 0; via < n ; via++){
                for(int i = 0; i < n ; i++){
                    for(int j = 0; j < n ; j++){

                        grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                    }
                }
            }


            //check if all shortest paths
            bool ok = true;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n ; j++){

                    if(i == j) continue;

                    if( ((set >> i) & 1) && ((set >> j) & 1)){
                        if(grid[i][j] > maxDistance){
                            ok = false;
                            break;
                        }
                    }
                }
            }

            if(ok){
                result++;
            }

        }

        return result;
    }
};