// Last updated: 02/05/2026, 22:40:27
class Solution {
public:
    int result = INT_MAX;
    int n;
    
    void solve(int idx, vector<int>& cookies, int& result, vector<int>& cookie){

        if(idx >= n){
            int unfairness = *max_element(cookie.begin(), cookie.end());
            result = min(result, unfairness);
            return;
        }

        for(int i = 0; i<cookie.size(); i++){

            //allocate cookie bag to kth child and call solve after that
            cookie[i] += cookies[idx];
            solve(idx+1, cookies, result, cookie);
            //backtrack and remove the allocation of kth child
            cookie[i] -= cookies[idx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int> cookie(k, 0);

        solve(0,cookies, result, cookie);

        return result;
    }
};