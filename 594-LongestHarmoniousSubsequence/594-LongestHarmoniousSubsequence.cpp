// Last updated: 02/05/2026, 22:44:13
class Solution {
public:
    int findLHS(vector<int>& nums) {
    
       int n = nums.size();
       map<int, int> freq;
       for(auto& num : nums) freq[num]++;

       vector<pair<int,int>> v;
       for(auto& [num, count]: freq) v.emplace_back(num, count);

       int longest_harmonious_length = 0;
       for(int i = 1; i < v.size(); i++){
            if(v[i].first - v[i - 1].first == 1){
                longest_harmonious_length = max(longest_harmonious_length, v[i].second + v[i - 1].second);
            }
       }

       return longest_harmonious_length;
    }
};