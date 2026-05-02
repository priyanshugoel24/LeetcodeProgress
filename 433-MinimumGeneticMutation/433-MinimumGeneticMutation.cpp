// Last updated: 02/05/2026, 22:44:53
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        //set to store all valid mutations
        unordered_set<string> mutations{bank.begin(), bank.end()};
        unordered_set<string> visited;
        
        //if end mutation is not valid return -1
        if(!mutations.count(endGene)) return -1;

        int level = 0;
        queue<string> q;
        q.push(startGene);

        while(!q.empty()){

            int size = q.size();
            while(size--){
                string curr = q.front();
                q.pop();

               if(curr == endGene){
                return level;
               }

               for(char ch : "ACGT"){

                for(int i = 0; i < curr.length(); i++){
                    string nbr = curr;
                    nbr[i] = ch;

                    if(mutations.find(nbr) != mutations.end() && visited.find(nbr) == visited.end()){
                        visited.insert(nbr);
                        q.push(nbr);
                    }
                }
               }
            }

            level++;
        }


        return -1;
    }
};