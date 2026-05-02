// Last updated: 02/05/2026, 22:38:01
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int rows = maze.size(); // no of rows in the maze
        int cols = maze[0].size(); // no of columns in the maze

        int moves = 1; // total no of moves required to exit the maze

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // possible movements

        queue<pair<int,int>> q; //q -> {row, col}, queue for bfs traversal
        q.push({entrance[0], entrance[1]}); // entrance coordinates

        maze[entrance[0]][entrance[1]] = '+'; // mark the entrance as visited

        while(!q.empty()){

            int size = q.size(); // curr size of the queue

            for(int i = 0; i < size; i++){

                pair<int,int> curr = q.front();
                q.pop();

                for(auto &dir : directions){

                    int new_r = curr.first + dir[0];
                    int new_c = curr.second + dir[1];

                    //check if safe move
                    if(new_r < 0 || new_r >= rows || new_c < 0 || new_c >= cols || maze[new_r][new_c] == '+'){
                        continue;
                    }

                    //check if reached the exit
                    if(new_r == 0 || new_c == 0 || new_r == rows - 1 || new_c == cols - 1){
                        return moves;
                    }

                    // mark the cell as visited
                    maze[new_r][new_c] = '+';
                    q.push({new_r, new_c});

                }
            }

            //increment the numer of moves
            moves++;
        }


        // if no path is possible return -1
        return -1;
    }
};