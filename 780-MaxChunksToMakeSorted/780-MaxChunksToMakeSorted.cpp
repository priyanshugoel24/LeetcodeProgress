// Last updated: 02/05/2026, 22:43:28
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, diff = 0;
        for(int i = 0; i<arr.size(); i++){
            diff += arr[i]-i;
            res += (diff == 0);
        }
        return res;
        
    }
};