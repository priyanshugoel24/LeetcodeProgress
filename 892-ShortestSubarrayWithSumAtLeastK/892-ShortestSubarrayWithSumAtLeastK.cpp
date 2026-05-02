// Last updated: 02/05/2026, 22:42:46
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        int len = INT_MAX;
        long long currSum = 0;
        deque<pair<long long , int>> q;

        for(int i = 0; i<nums.size(); i++){
            currSum += nums[i];

            if(currSum >= k) len = min(len, i+1);
        

            while(!q.empty() && currSum - q.front().first >= k){
                auto [prefix, endIdx] = q.front();
                q.pop_front();
                len = min(len, i - endIdx);
            }
        

            while(!q.empty() && q.back().first > currSum) q.pop_back();

            q.push_back({currSum, i});
        }

        return len == INT_MAX ? -1 : len;
        
    }
};