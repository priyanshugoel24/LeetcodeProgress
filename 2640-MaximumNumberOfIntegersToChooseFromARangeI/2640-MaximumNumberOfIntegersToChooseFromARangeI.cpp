// Last updated: 02/05/2026, 22:35:30
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        set<int> bannedNos(banned.begin(), banned.end());

        int count = 0;

        for(int i = 1; i<=n; i++){

            if(bannedNos.find(i) != bannedNos.end()) continue;
            else if(i > maxSum) break;
            else{
                maxSum -= i;
                count++;
            }
        }

        return count;
        
    }
};