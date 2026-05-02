// Last updated: 02/05/2026, 22:42:51
class Solution {
public:
    typedef pair<int, int> P;
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();

        if(n == 1 || n == 0){
            return 0;
        }

        queue<P> q;
        set<P> visited;

        for(int i = 0; i < n; i++){

            int maskValue = (1 << i);

            q.push({i, maskValue});

            visited.insert({i, maskValue});
        }

        int allVisitedState = (1 << n) - 1;

        int path = 0;

        while(!q.empty()){

            int size = q.size();
            path++;

            while(size--){

                auto curr = q.front();
                q.pop();

                int currNode = curr.first;
                int currMask = curr.second;

                for(auto& adj : graph[currNode]){

                    int nextMask = currMask | (1 << adj);

                    if(nextMask == allVisitedState){
                        return path;
                    }

                    if(visited.find({adj, nextMask}) == visited.end()){
                        visited.insert({adj, nextMask});
                        q.push({adj, nextMask});
                    }
                }
            }
        }

        return -1;


    }
};