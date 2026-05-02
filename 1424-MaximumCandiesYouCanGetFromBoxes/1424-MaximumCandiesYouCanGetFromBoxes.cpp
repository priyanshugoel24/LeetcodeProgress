// Last updated: 02/05/2026, 22:40:24
class Solution {
public:
    int dfs(int box, vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,unordered_set<int>& visited,
        unordered_set<int>& foundBoxes){

        if(visited.count(box)){
            return 0;
        }

        if(status[box] == 0){
            foundBoxes.insert(box);
            return 0;
        }

        visited.insert(box);

        int candies_collected = candies[box];

        for(int &insideBox : containedBoxes[box]){
            candies_collected += dfs(insideBox, status, candies, keys, containedBoxes, visited, foundBoxes);
        }

        for(int &key : keys[box]){
            status[key] = 1;
            if(foundBoxes.count(key)){
                candies_collected += dfs(key, status, candies, keys, containedBoxes, visited, foundBoxes);
            }
        }

        return candies_collected;

    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int total_candies = 0;
        unordered_set<int> visited;
        unordered_set<int> foundBoxes;
        for(int &box : initialBoxes){

            total_candies += dfs(box, status, candies, keys, containedBoxes, visited, foundBoxes);
        }

        return total_candies;

    }
};