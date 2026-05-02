// Last updated: 02/05/2026, 22:38:16
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<int> curr(4, 0); // Current minimum side jumps needed for each lane
        vector<int> nxt(4, 0);  // Next state of minimum side jumps

        // Traverse from second last point to the first point
        for (int i = obstacles.size() - 2; i >= 0; i--) {
            for (int lane = 1; lane <= 3; lane++) {
                if (obstacles[i + 1] != lane) {
                    curr[lane] = nxt[lane]; // No side jump needed, carry forward from next state
                } else {
                    int jumpToLane1 = INT_MAX, jumpToLane2 = INT_MAX;
                    if (lane == 1) {
                        if (obstacles[i] != 2) {
                            jumpToLane1 = min(jumpToLane1, 1 + nxt[2]);
                        }
                        if (obstacles[i] != 3) {
                            jumpToLane2 = min(jumpToLane2, 1 + nxt[3]);
                        }
                    } else if (lane == 2) {
                        if (obstacles[i] != 1) {
                            jumpToLane1 = min(jumpToLane1, 1 + nxt[1]);
                        }
                        if (obstacles[i] != 3) {
                            jumpToLane2 = min(jumpToLane2, 1 + nxt[3]);
                        }
                    } else { // lane == 3
                        if (obstacles[i] != 1) {
                            jumpToLane1 = min(jumpToLane1, 1 + nxt[1]);
                        }
                        if (obstacles[i] != 2) {
                            jumpToLane2 = min(jumpToLane2, 1 + nxt[2]);
                        }
                    }
                    curr[lane] = min(jumpToLane1, jumpToLane2);
                }
            }
            nxt = curr; // Update next state to current state for the next iteration
        }
        return curr[2]; // Return the minimum side jumps needed to reach lane 2 at the last point
    }
};