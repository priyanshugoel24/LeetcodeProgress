// Last updated: 02/05/2026, 22:39:10
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = colors.length();

        int min_cost = 0;

        int i = 0;

        while(i < n){

            char curr_color = colors[i];

            int totalTime = neededTime[i];
            int maxTime = neededTime[i];
            int j = i + 1;

            
            while(j < n && colors[j] == curr_color){

                totalTime += neededTime[j];
                maxTime = max(maxTime, neededTime[j]);
                j++;

            }

            
           

                min_cost += (totalTime - maxTime);
            

            i = j;
        }

        return min_cost;
    }
};