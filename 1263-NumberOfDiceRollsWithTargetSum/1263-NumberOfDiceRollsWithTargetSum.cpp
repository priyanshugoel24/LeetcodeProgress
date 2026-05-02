// Last updated: 02/05/2026, 22:41:11
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);
        prev[0] = 1;
        int mod = 1e9 + 7;

        for(int dice = 1; dice<=n; dice++){
            for(int t = 1; t<= target; t++){
                int ans = 0;
                for(int i = 1; i<=k; i++){
                    if(t-i >= 0)
                        ans = (ans + (prev[t-i]) % mod) % mod;
                }
                curr[t] = ans;
            }
            prev = curr;
        }

        return prev[target] % mod;
        
    }
};