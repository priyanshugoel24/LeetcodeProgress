// Last updated: 02/05/2026, 22:43:19
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        unordered_map<int, int> freq;

        for(int &num : answers){
            freq[num]++;
        }

        int rabbits = 0;

        for(auto [num, count] : freq){

            int presentRabbits = count;
            int additionalRabbitsNedded = (num + 1 - (count % (num + 1))) % (num + 1);

            rabbits += presentRabbits + additionalRabbitsNedded;
        }

        return rabbits;
    }
};