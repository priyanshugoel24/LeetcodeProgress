// Last updated: 02/05/2026, 22:46:19
class Solution {
private:
vector<vector<int>> ans;
public:
    void f(int k, int n, int data, vector<int>& temp){
        if(k == 0){
            if(n == 0){
                ans.push_back(temp);
                return;
            }
        }

        if(k < 0 || n < 0 || data > 9) return;

        temp.push_back(data);
        f(k-1, n-data, data+1, temp);
        temp.pop_back();
        f(k, n, data+1, temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {       
        vector<int> temp;
        f(k, n, 1, temp);
        return ans;
        
    }
};