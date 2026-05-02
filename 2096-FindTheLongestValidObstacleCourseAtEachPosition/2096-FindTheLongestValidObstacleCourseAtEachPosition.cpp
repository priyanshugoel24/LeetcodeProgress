// Last updated: 02/05/2026, 22:37:47
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();

        vector<int> lis;
        vector<int> result(n);

        for(int i = 0; i < n; i++){

            int idx = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin();

            if(idx == lis.size()){
                lis.push_back(obstacles[i]);
            } else{
                lis[idx] = obstacles[i];
                //idx+1 = length of subsequence
                //ending element obstacles[i];
            }

            result[i] = idx+1;
        }

        return result;
    }
};