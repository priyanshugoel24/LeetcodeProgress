// Last updated: 02/05/2026, 22:48:42
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int prev[n]; //prev greatest element
        int max = height[0];
        prev[0] = -1;

        for(int i = 1; i<n; i++){
            prev[i] = max;
            if(max<height[i]) max = height[i];
        }

        //next greatest element
        int next[n];
        max = height[n-1];
        next[n-1] = -1;
        for(int i = n-2; i>=0 ; i--){
            next[i] = max;
            if(max < height[i]) max = height[i];
        }

        //minimum array -> prev array
        for(int i = 0; i<n; i++){
            prev[i] = min(prev[i], next[i]);
        }

        int water = 0;
        for(int i = 1; i<n-1; i++){
            if(height[i] < prev[i]) water += (prev[i] - height[i]);
        }
        

        return water;
    }
};