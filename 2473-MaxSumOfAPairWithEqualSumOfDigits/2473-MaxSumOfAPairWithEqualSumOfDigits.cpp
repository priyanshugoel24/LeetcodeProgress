// Last updated: 02/05/2026, 22:36:05
class Solution {
public:
    int maximumSum(vector<int>& nums) {

       unordered_map<int, priority_queue<int>> mp;
       for(int num : nums){
        int sum = 0, n = num;
        while(n){
            sum += n % 10;
            n /= 10;
        }

        mp[sum].push(num);
       }

       int ans = -1;
       for(auto& it : mp){
        if(it.second.size() > 1){
            int sum = it.second.top();
            it.second.pop();
            sum += it.second.top();
            ans = max(ans, sum);
        }
       }

       return ans;

        
        
    }
};