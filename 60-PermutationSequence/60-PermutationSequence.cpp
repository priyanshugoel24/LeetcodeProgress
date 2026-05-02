// Last updated: 02/05/2026, 22:48:25
class Solution {
public:
    string getPermutation(int n, int k) {
         int fact = 1;
        string res = "";
        vector<int> arr;
        for(int i = 1; i <= n; i++)
        {
            fact *= i;
            arr.push_back(i);
        }
        
        //we are using zero based indexing
        k--;
        while(arr.size() > 0)
        {            
            fact = fact/arr.size();
            res += to_string(arr[k/fact]);
            arr.erase(arr.begin() + k/fact);
            k = k%fact;
        }
        return res;
        
    }
};