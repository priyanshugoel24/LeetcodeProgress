// Last updated: 02/05/2026, 22:45:05
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> times;

        for(int h = 0; h<12; h++){
            for(int m = 0; m<60; m++){
                int hOnes = bitset<4>(h).count();
                int mOnes = bitset<6>(m).count();

                if(hOnes + mOnes == turnedOn){
                    times.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                }
            }
        }

        return times;
    }
};