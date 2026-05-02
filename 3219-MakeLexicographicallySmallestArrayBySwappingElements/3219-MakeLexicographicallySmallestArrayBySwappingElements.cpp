// Last updated: 02/05/2026, 22:34:09
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> vec = nums;
        sort(begin(vec), end(vec));

        int groupNo = 0;
        unordered_map<int,int> numToGroup;
        numToGroup[vec[0]] = groupNo;

        unordered_map<int, list<int>> groupToList;
        groupToList[groupNo].push_back(vec[0]);

        for(int i = 1; i<n; i++){
            if(abs(vec[i] - vec[i-1]) > limit) groupNo += 1;

            numToGroup[vec[i]] = groupNo;
            groupToList[groupNo].push_back(vec[i]);
        } 

        for(int i = 0; i<n; i++){
            int num = nums[i];
            int group = numToGroup[num];

            nums[i] = *(groupToList[group].begin());
            groupToList[group].pop_front();
        }

        return nums;
        
    }
};