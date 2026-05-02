// Last updated: 02/05/2026, 22:43:31
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> invalid(deadends.begin(), deadends.end());
        unordered_set<string> visited;

        if(invalid.count(target)) return -1;

        queue<string> q;
        q.push("0000");
        visited.insert("0000");

        int turns_required = 0;

        while(!q.empty()){

            int size = q.size();

            while(size--){

                string curr = q.front();
                q.pop();
                visited.insert(curr);

                if(invalid.count(curr)) continue;
                
                if(curr == target) return turns_required;

                for(int i = 0; i < 4; i++){

                    string forward = curr, backward = curr;

                    forward[i] = (curr[i] == '9') ? '0' : curr[i] + 1;
                    backward[i] = (curr[i] == '0') ? '9' : curr[i] - 1;

                    if (!visited.count(forward) && !invalid.count(forward)) {
                        visited.insert(forward);
                        q.push(forward);
                    }

                    if (!visited.count(backward) && !invalid.count(backward)) {
                        visited.insert(backward);
                        q.push(backward);
                    }
                }
            }

            turns_required++;

        }


        return -1;
    }
};