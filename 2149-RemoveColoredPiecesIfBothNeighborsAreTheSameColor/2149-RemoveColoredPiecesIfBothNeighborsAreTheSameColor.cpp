// Last updated: 02/05/2026, 22:37:37
class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int n = colors.length();

        if(n <= 2) return false;

        int movesA = 0, movesB = 0;
        int i = 0;

        while(i < n){

            int j = i;

            while(j < n && colors[j] == colors[i]) {
                j++;
            }

            int len = j - i;
            if(colors[i] == 'A' && len >= 3)
                movesA += (len - 2);
            else if(colors[i] == 'B' && len >= 3)
                movesB += (len - 2);

            i = j;
        }

        bool alice_wins = movesA > movesB;

        return alice_wins;
    }
};
