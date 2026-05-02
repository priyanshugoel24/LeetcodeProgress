// Last updated: 02/05/2026, 22:35:47
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
        vector<int> bins;
        int rep = 1;
        while(n){

            if(n%2 == 1){
                bins.push_back(rep);
            }

            n /= 2;
            rep *= 2;
        }

        const int mod = 1e9 + 7;

        vector<int> ans;

        for(auto& query : queries){

            int curr = 1;
            for(int i = query[0]; i <= query[1]; i++){

                curr = static_cast<long long>(curr) * bins[i] % mod;
            }

            ans.push_back(curr);
        }

        return ans;
    }
};