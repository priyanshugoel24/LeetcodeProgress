// Last updated: 02/05/2026, 22:41:14
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        if(arr.size() == 0) return {};
        if(arr.size() == 1) return {1};

        map<int,int> mp;
        vector<int> ans(arr.begin(), arr.end());
        sort(ans.begin(), ans.end());

        int cnt = 1;
        mp[ans[0]] = cnt;

        for(int i = 1; i<arr.size(); i++){

            if(ans[i] == ans[i-1]) mp[ans[i]] = cnt;
            else mp[ans[i]] = ++cnt;
        }

        for(int i = 0; i<arr.size(); i++){
            arr[i] = mp[arr[i]];
        }

        return arr;
        
    }
};