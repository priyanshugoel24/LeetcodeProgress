// Last updated: 02/05/2026, 22:38:50
class Solution {
public:
    int minPartitions(string n) {
        
        return *max_element(n.begin(), n.end()) - '0';

        
    }
};