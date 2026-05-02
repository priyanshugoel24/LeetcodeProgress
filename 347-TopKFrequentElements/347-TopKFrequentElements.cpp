// Last updated: 02/05/2026, 22:45:17
class Solution {
public:
    using P = pair<int,int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> cnt;
        for(int num : nums) cnt[num]++;
        

        vector<int> result;

        priority_queue<P> maxHeap;

        for(auto& [num, count] : cnt){
            maxHeap.push({count, num});
        } 
        
        while(k--){

            auto [_, num] = maxHeap.top(); maxHeap.pop();
            result.push_back(num);
        }

        return result;
        
    }
};