// Last updated: 02/05/2026, 22:34:18
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        
        int n = nums.size();
        map<int,long long > mp;// nums[i] - i, sum

        long result = INT_MIN;

        for(int i = 0; i<n; i++){

            auto it = mp.upper_bound(nums[i] - i);// it->first = (nums[j] - j), it->second = sum

            long long sum = nums[i];

            if(it != mp.begin()){
                it--;
                sum += it->second;
            }

            mp[nums[i] - i] = max(mp[nums[i] - i], sum);

            it = mp.upper_bound(nums[i] - i);

            while(it != mp.end() && it->second <= sum){
                mp.erase(it++);
            }

            result = max<long long>(result, sum);
        }

        return result;
    }
};