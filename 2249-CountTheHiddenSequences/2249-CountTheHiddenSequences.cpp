// Last updated: 02/05/2026, 22:37:02
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        int n = differences.size();

        int currVal = 0; // first element of hidden sequence
        int minVal = 0; // min possible value of first element
        int maxVal = 0; // max possible value of first element

        for(int &diff : differences){
            
            currVal = currVal + diff;

            //updating max and min values
            minVal = min(minVal, currVal);
            maxVal = max(maxVal, currVal);

            // no possible hidden sequence as any element would be out of range
            if((upper - maxVal) - (lower - minVal) + 1 <= 0){
                return 0;
            }
        }

        int sequences = (upper - maxVal) - (lower - minVal) + 1;
        
        return sequences;
    }
};