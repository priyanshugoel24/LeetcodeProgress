// Last updated: 02/05/2026, 22:40:08
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        unordered_set<int> st;

        for(int num : arr){
            if(!st.empty()){
                if(st.count(num * 2) || (num % 2 == 0 && st.count(num / 2))) return true;
                
            }
           st.insert(num);
        }
        

        return false;
    }
};