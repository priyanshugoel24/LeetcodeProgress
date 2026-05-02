// Last updated: 02/05/2026, 22:36:40
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        int n = tasks.size();

        if(n == 1){
            return -1;
        }

        int no_of_rounds = 0;

        unordered_map<int,int> freq;
        for(auto& task : tasks){
            freq[task]++;
        }

        for(auto& [task, count] : freq){

            if(count == 1){
                return -1;
            }

            no_of_rounds += (count + 2) / 3;
        }

        return no_of_rounds;
    }
};