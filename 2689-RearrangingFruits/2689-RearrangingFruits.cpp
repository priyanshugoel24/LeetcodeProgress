// Last updated: 02/05/2026, 22:35:16
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        
        int mini = INT_MAX;
        unordered_map<int, int> mp;

        for(int& x : basket1){
            mp[x]++;

            mini = min(mini, x);
        }

        for(int& x : basket2){
            mp[x]--;

            mini = min(mini, x);
        }

        vector<int> finalList;

        for(auto& [cost, count] : mp){

            if(count == 0) continue;

            if(count % 2 != 0) return -1;

            for(int c = 1; c <= abs(count) / 2; c++){
                finalList.push_back(cost);
            }

        }

        nth_element(begin(finalList), begin(finalList) + finalList.size() / 2, end(finalList));

        long long result = 0;

        for(int i = 0; i < finalList.size() / 2; i++){

            result += min(finalList[i], mini*2);
        }

        return result;
    }
};