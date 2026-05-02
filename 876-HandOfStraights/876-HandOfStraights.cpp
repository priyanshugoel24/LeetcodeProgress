// Last updated: 02/05/2026, 22:42:52
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n = hand.size();

        if(groupSize == 1){
            return true;
        }

        if(n % groupSize != 0){
            return false;
        }

        map<int, int> mp;

        for(int& num : hand){
            mp[num]++;
        }

        while(!mp.empty()){

            int curr_num = mp.begin()->first;

            for(int i = 0; i < groupSize; i++){

                int next_num = curr_num + i;

                if(mp.find(next_num) == mp.end()){
                    return false;
                }

                mp[next_num]--;

                if(mp[next_num] == 0){
                    mp.erase(next_num);
                }

                
            }
        }

        return true;
    }
};