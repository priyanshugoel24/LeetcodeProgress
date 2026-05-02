// Last updated: 02/05/2026, 22:45:02
class Solution {
public:
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();

        unordered_map<int, int> posToIdx;
        for(int i = 0; i < n; i++){
            posToIdx[stones[i]] = i;
        }

        vector<unordered_set<int>> dp(n);
        dp[0].insert(0);

        for(int i = 0; i < n; i++){

            for(int k : dp[i]){

                for(int step = k - 1; step <= k + 1; step++){

                    if(step > 0){

                        int nextPos = stones[i] + step;

                        if(posToIdx.count(nextPos)){
                            int j = posToIdx[nextPos];
                            dp[j].insert(step);
                        }
                    }
                }
            }
        }

        if(dp[n - 1].empty()) return false;

        return true;
    }
};