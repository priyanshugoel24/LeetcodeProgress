// Last updated: 02/05/2026, 22:34:43
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        unordered_set<int> st(nums.begin(), nums.end());
        //to store distinct elements in nums

        int totalDistinctElements = st.size();
        int completeSubarrays = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){

            unordered_set<int> curr; //set to store distinct elements in curr window
            
            for(int j = i; j < n; j++){
                
                //populate the set
                curr.insert(nums[j]);

                //if size is equal to total distinct elements possible we have found complete subarray window
                if(curr.size() == totalDistinctElements){
                    completeSubarrays += (n - j);
                    break;
                }
            }
        }

        return completeSubarrays;
    }
};