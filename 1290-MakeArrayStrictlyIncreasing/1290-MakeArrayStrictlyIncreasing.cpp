// Last updated: 02/05/2026, 22:41:06
class Solution {
public:
    int solve(int idx,vector<int>& arr1, vector<int>& arr2, int prev, map<pair<int,int> , int>& mp){

        if(idx >= arr1.size()){
            return 0;
        }

        if(mp.find({idx, prev}) != mp.end()){
            return mp[{idx, prev}];
        }

        int result1 = 1e9 + 1;

        if(arr1[idx] > prev){
            result1 = solve(idx+1, arr1, arr2, arr1[idx], mp);
        }

        int result2 = 1e9+ 1;

        auto it = upper_bound(arr2.begin(), arr2.end(), prev);

        if(it != end(arr2)){
            int j = it - begin(arr2);

            result2 = 1 + solve(idx+1, arr1, arr2, arr2[j], mp);
        }

        return mp[{idx, prev}] = min(result1, result2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        map<pair<int,int> , int> mp;

        int result = solve(0, arr1, arr2, INT_MIN, mp);

        return (result == 1e9 + 1) ? -1 : result;
        
    }
};