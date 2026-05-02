// Last updated: 02/05/2026, 22:33:22
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();


        int flips = 0;
        int flipCountforidx = 0;
        deque<int> flipQue;

        for(int i = 0; i<n; i++){
            if(i >= 3){
                flipCountforidx -= flipQue.front();
                flipQue.pop_front();
            }

            if(flipCountforidx % 2 == nums[i]){

                if(i + 3 > n) return -1;

                flipCountforidx++;
                flips++;
                flipQue.push_back(1);
            }else{
                flipQue.push_back(0);
            }
        }

        return flips;
    }
};