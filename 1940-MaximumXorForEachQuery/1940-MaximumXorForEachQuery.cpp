// Last updated: 02/05/2026, 22:38:18
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {

        int n = nums.size();
        vector<int> result(n);
        
        int Xor = 0;
        for(int i = 0; i<n; i++){
            Xor ^= nums[i];

        }

        int mask = ((1 << maximumBit) - 1);

        for(int i = 0; i<n; i++){
            int ans = Xor^mask;
            result[i] = ans; 

            Xor ^= nums[n-i-1];
        }

        return result;

        
        
    }
};