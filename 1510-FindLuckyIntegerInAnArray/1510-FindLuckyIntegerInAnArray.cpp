// Last updated: 02/05/2026, 22:39:54
class Solution {
public:
    int findLucky(vector<int>& arr) {
        
        unordered_map<int, int> freq;
        for(int i = 0; i < arr.size(); i++) freq[arr[i]]++;

        int lucky_no = -1;

        for(auto& [num, count] : freq){

            if(num == count){

                lucky_no = max(lucky_no, num);
            }
        }

        return lucky_no;
    }
};