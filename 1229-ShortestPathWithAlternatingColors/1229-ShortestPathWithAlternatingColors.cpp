// Last updated: 02/05/2026, 22:41:21
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        

        unordered_map<int, vector<int>> redGraph; // adjacency list for red color edged graph
        unordered_map<int, vector<int>> blueGraph; // adjacency list for blue color edged graph

        //building red graph
        for(auto& edge : redEdges){

            int u = edge[0], v = edge[1];

            redGraph[u].push_back(v);
        }

        //building blue graph
        for(auto& edge : blueEdges){

            int u = edge[0], v = edge[1];

            blueGraph[u].push_back(v);
        }

        vector<int> answer(n, -1); // answer[i] is shortest path from 0 to i with alternating color edges
        answer[0] = 0;

        vector<vector<bool>> visited(n, vector<bool>(2, false));
        // visited[i][0] -> i is visited with red edge
        //visited[i][1] -> i is visited with blue edge

        queue<tuple<int,int,int>> q;
        // q-> {node, dist, color}

        //try 0th node with both red and blue color
        q.push({0, 0, 0});
        q.push({0, 0, 1});

        while(!q.empty()){

            auto [node, dist, color] = q.front();
            q.pop();

            // current edge color is red
            if(color == 0){
                
                // try next edge with blue color
                for(auto& nbr : blueGraph[node]){

                    if(!visited[nbr][1]){
                        visited[nbr][1] = true;

                        q.push({nbr, dist + 1, 1});

                        // when discovering the nbr update its shortest distance
                        if(answer[nbr] == -1){
                            answer[nbr] = dist + 1;
                        }
                    }
                }
            }else{ // current edge color is blue

                // try next edge with red color
                for(auto& nbr : redGraph[node]){

                    if(!visited[nbr][0]){

                        visited[nbr][0] = true;

                        q.push({nbr, dist + 1, 0});

                        if(answer[nbr] == -1){

                            answer[nbr] = dist + 1;
                        }
                    }
                }

            }
        }


        return answer;


    }
};