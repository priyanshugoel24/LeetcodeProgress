// Last updated: 02/05/2026, 22:39:01
class Solution {
public:
    int validRequestsCompleted = 0;
    
    void solve(int idx, vector<int>& buildings, vector<vector<int>>& requests, int& ans, int count) {
        // Base case: If all requests are processed
        if (idx == requests.size()) {
            // Check if all buildings have zero net transfers (valid state)
            if (all_of(buildings.begin(), buildings.end(), [](int x) { return x == 0; })) {
                ans = max(ans, count);
            }
            return;
        }

        // Option 1: Ignore the current request and move to the next
        solve(idx + 1, buildings, requests, ans, count);

        // Option 2: Take the current request
        int from = requests[idx][0], to = requests[idx][1];

        buildings[from]--;
        buildings[to]++;

        // Include this request and recurse
        solve(idx + 1, buildings, requests, ans, count + 1);

        // Backtrack to undo the state
        buildings[from]++;
        buildings[to]--;
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans = 0;
        vector<int> buildings(n, 0);

        solve(0, buildings, requests, ans, 0);

        return ans;
    }
};