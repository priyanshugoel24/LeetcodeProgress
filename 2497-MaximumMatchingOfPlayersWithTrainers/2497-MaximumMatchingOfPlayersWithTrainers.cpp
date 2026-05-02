// Last updated: 02/05/2026, 22:35:56
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        int n = players.size();
        int m = trainers.size();

        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));

        int no_of_matches = 0;

        int i = 0, j = 0;

        while(i < n && j < m){

            if(players[i] <= trainers[j]){
                no_of_matches++;
                i++,j++;
            }else{

                j++;
            }
        }

        return no_of_matches;
    }
};