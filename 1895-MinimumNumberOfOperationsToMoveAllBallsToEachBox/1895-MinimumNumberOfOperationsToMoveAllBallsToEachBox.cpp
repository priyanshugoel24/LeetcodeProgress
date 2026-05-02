// Last updated: 02/05/2026, 22:38:28
class Solution {
public:
    vector<int> minOperations(string boxes) {

        int n = boxes.size();

        vector<int> ans(n, 0);

        int cumValue = 0, cumValueSum = 0;

        //cumSum from left
        for(int i = 0; i<n; i++){
            ans[i] = cumValueSum;
            cumValue += boxes[i] == '1' ? 1 : 0;
            cumValueSum += cumValue;
        }

        cumValue = 0, cumValueSum = 0;

        //cumSum from right
        for(int i = n-1; i>=0; i--){
            ans[i] += cumValueSum;
            cumValue += boxes[i] == '1' ? 1 : 0;
            cumValueSum += cumValue;
        }

        return ans;

        
    }
};