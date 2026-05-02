// Last updated: 02/05/2026, 22:41:54
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int n = tops.size(); // no of dominoes

        int minRotations = INT_MAX; // min no of rotations required to make all values equal in either tops or bottoms

        // Try every possible domino value from 1 to 6
        for (int target = 1; target <= 6; target++) {
            
            // Try to make all values in tops equal to target
            int topRotations = 0; 
            int bottomRotations = 0;

            bool possible = true;

            for (int i = 0; i < n; i++) {

                // if neither top nor bottom has the target, it's impossible to make arrays equal to this target
                if (tops[i] != target && bottoms[i] != target) {
                    possible = false;
                    break;
                }

                // if top is not target, we must rotate domino
                if (tops[i] != target) topRotations++;

                // if bottom is not target, we must rotate domino
                if (bottoms[i] != target) bottomRotations++;
            }

            // update min rotations if it's possible for this target
            if (possible) {
                minRotations = min(minRotations, min(topRotations, bottomRotations));
            }
        }

        // return min rotations required to make either array equal
        return minRotations == INT_MAX ? -1 : minRotations;
    }
};