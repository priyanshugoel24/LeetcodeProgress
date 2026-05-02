// Last updated: 02/05/2026, 22:40:45
class Solution {
public:
    unordered_map<string, int> mp;
    bool hasDuplicates(string &s1, string &s2){

        int arr[26] = {0};

        for(char &ch : s1){
            if(arr[ch - 'a'] > 0) return true;
            arr[ch - 'a']++;
        }

        for(char &ch : s2){
            if(arr[ch - 'a'] > 0) return true;
        }

        return false;

    }
    int solve(int idx, vector<string>& arr, string temp, int n){
        if(idx >= n){
            return temp.length();
        }

        if(mp.find(temp) != mp.end()){
            return mp[temp];
        }

        int include = 0;
        int exclude = 0;

        if(hasDuplicates(arr[idx], temp)){
            exclude = solve(idx+1, arr, temp, n);
        }else{
            exclude = solve(idx+1, arr, temp, n);

            include = solve(idx+1, arr, temp + arr[idx], n);
        }

        return mp[temp] =  max(include, exclude);

    }
    int maxLength(vector<string>& arr) {
        string temp = "";
        mp.clear();
        int n = arr.size();

        return solve(0, arr, temp, n);
    }
};