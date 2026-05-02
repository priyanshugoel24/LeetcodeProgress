// Last updated: 02/05/2026, 22:33:49
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        nums.push_back(k);
        priority_queue<int, vector<int>, greater<>> pq(nums.begin(), nums.end());
        int ans = 0;

        while(pq.top() < k && pq.size() >= 2){
            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            if(2LL*x+y < k){
                pq.push(2*x+y);
            }
            ans++;
        }
        

        return ans;
    }
};