// Last updated: 02/05/2026, 22:37:18
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        int n = nums.size();

        vector<int> result;
        priority_queue<pair<int,int>> pq;
        vector<bool> taken(n, false);

        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        while(k > 0){

            auto [ele, idx] = pq.top();
            pq.pop();

            taken[idx] = true;
            k--;

        }

        for(int i = 0; i < n; i++){

            if(taken[i]){
                result.push_back(nums[i]);
            }
        }

        return result;
    }
};