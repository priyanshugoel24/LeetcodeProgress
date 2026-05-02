// Last updated: 02/05/2026, 22:33:14
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        vector<pair<int,int>> vec(n);

        for(int i = 0; i<n; i++){
            vec[i] = {nums[i], i};
        }

        make_heap(begin(vec), end(vec), greater<>());

        while(k--){
            pop_heap(begin(vec), end(vec), greater<>());
            pair<int,int> temp = vec.back();
            vec.pop_back();

            int idx = temp.second;
            int num = temp.first;

            nums[idx] = num * multiplier;

            vec.push_back({nums[idx], idx});

            push_heap(begin(vec), end(vec), greater<>());
        }

        return nums;
        
    }
};