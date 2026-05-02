// Last updated: 02/05/2026, 22:43:03
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    if (source == target) return 0;

    unordered_map<int, vector<int>> stopToBuses;

    // Map each stop to the list of buses (routes) that go through it
    for (int i = 0; i < routes.size(); ++i) {
        for (int stop : routes[i]) {
            stopToBuses[stop].push_back(i);
        }
    }

    queue<int> q; // stores bus stops
    unordered_set<int> visitedStops;
    unordered_set<int> visitedBuses;

    q.push(source);
    visitedStops.insert(source);

    int busesTaken = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        busesTaken++; // each level means boarding a new bus

        for (int i = 0; i < levelSize; ++i) {
            int stop = q.front();
            q.pop();

            for (int bus : stopToBuses[stop]) {
                if (visitedBuses.count(bus)) continue;
                visitedBuses.insert(bus);

                for (int nextStop : routes[bus]) {
                    if (nextStop == target) return busesTaken;
                    if (!visitedStops.count(nextStop)) {
                        visitedStops.insert(nextStop);
                        q.push(nextStop);
                    }
                }
            }
        }
    }

    return -1; // not reachable

        
    }
};