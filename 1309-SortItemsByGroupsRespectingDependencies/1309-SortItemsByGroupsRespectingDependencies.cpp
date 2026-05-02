// Last updated: 02/05/2026, 22:40:58
class Solution {
public:

    // Performs topological sort on the given graph and returns the order.
    vector<int> topoSort(unordered_map<int, vector<int>>& adj, vector<int>& indegree) {
        queue<int> q;

        // Start with all nodes having indegree 0
        for (int i = 0; i < adj.size(); ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);

            // Decrease indegree of adjacent nodes
            for (int& v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // If result size doesn't match graph size, cycle exists
        return result.size() == adj.size() ? result : vector<int>();
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // Step 1: Assign a unique group to ungrouped items (-1)
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = m++; // Assign new group ID and increment total groups
            }
        }

        // Step 2: Build item-level graph and indegree
        unordered_map<int, vector<int>> itemGraph;
        vector<int> itemIndegree(n, 0);
        for (int i = 0; i < n; ++i) {
            itemGraph[i] = vector<int>();
        }

        // Step 3: Build group-level graph and indegree
        unordered_map<int, vector<int>> groupGraph;
        vector<int> groupIndegree(m, 0);
        for (int i = 0; i < m; ++i) {
            groupGraph[i] = vector<int>();
        }

        // Step 4: Populate both graphs based on dependencies
        for (int i = 0; i < n; ++i) {
            for (int prev : beforeItems[i]) {
                // Add item-level edge: prev → i
                itemGraph[prev].push_back(i);
                itemIndegree[i]++;

                // If items belong to different groups, add group-level edge
                if (group[i] != group[prev]) {
                    int prevGroup = group[prev];
                    int currGroup = group[i];

                    groupGraph[prevGroup].push_back(currGroup);
                    groupIndegree[currGroup]++;
                }
            }
        }

        // Step 5: Topological sort on items and groups
        vector<int> itemOrder = topoSort(itemGraph, itemIndegree);
        vector<int> groupOrder = topoSort(groupGraph, groupIndegree);

        // If cycle detected in any graph, return empty
        if (itemOrder.empty() || groupOrder.empty()) {
            return {};
        }

        // Step 6: Map items into groups according to item order
        unordered_map<int, vector<int>> groupToItemsInOrder;
        for (int& item : itemOrder) {
            int grp = group[item];
            groupToItemsInOrder[grp].push_back(item);
        }

        // Step 7: Concatenate final result by following group order
        vector<int> result;
        for (int& grp : groupOrder) {
            vector<int>& items = groupToItemsInOrder[grp];
            result.insert(result.end(), items.begin(), items.end());
        }

        return result;
    }
};
