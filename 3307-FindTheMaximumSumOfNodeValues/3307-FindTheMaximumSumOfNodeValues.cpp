// Last updated: 02/05/2026, 22:33:55
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        
        int n = nums.size();
        long long dp0 = 0, dp1 = INT_MIN;

        for(int i = 1; i<=n; i++){
            long long x = nums[i - 1], xk = x^k;
            long long dp_0 = max(x + dp0, xk + dp1);
            dp1 = max(x + dp1, xk + dp0);
            dp0 = dp_0;
        }

        return dp0;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();