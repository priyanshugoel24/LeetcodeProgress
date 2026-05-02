// Last updated: 02/05/2026, 22:33:32
class Solution {
public:
    int n;
    int minScore = INT_MAX;
    vector<int> resultPerm;


    void solve(vector<int>& nums, vector<bool>& visited, vector<int>& perm, int score){
        if(score > minScore){
            return;
        }
        if(perm.size() == n){

            score += abs(perm.back() - nums[perm[0]]);

            if(minScore > score){
                minScore = score;
                resultPerm = perm;
            }

            return;
        }

        for(int num = 0; num<n; num++){
            if(!visited[num]){
                visited[num] = true;
                perm.push_back(num);
                int s = perm.size();
                solve(nums, visited, perm, score + abs(perm[s-2] - nums[perm[s-1]]));

                visited[num] = false;
                perm.pop_back();
            }
        }
    }
    vector<int> findPermutation(vector<int>& nums) {
        n = nums.size();

        vector<bool> visited(n, false);

        vector<int> perm = {0};
        visited[0] = true;

        solve(nums, visited, perm, 0);

        return resultPerm;

    }
};