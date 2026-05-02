// Last updated: 02/05/2026, 22:33:06
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // store the frequency of numbers greater than k

        for(int num : nums){
            
            // if any number is less than k there is no way to make all elements equal to k
            if(num < k){
                return -1; // no way possible
            }
            else if( num > k){
                mp[num]++; // increase the frequency of numbers greater than k
            }
        }

        int minOperationsRequired = mp.size(); // no of distinct numbers is the operations required

        return minOperationsRequired;
    }
};