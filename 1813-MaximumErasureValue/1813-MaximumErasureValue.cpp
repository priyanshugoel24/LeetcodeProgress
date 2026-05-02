// Last updated: 02/05/2026, 22:38:47
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n = nums.size();

        int max_score = 0;
        int curr_score = 0;
        unordered_set<int> elements;

        int l = 0, r = 0;

        while(r < n){

            int curr_no = nums[r];

            //check for duplicate
            while(elements.find(curr_no) != elements.end()){
               
                elements.erase(nums[l]);
                curr_score -= nums[l];
                l++;
            
            }

           elements.insert(curr_no);
           curr_score += curr_no;
           max_score = max(max_score, curr_score);

            r++;

        }


        return max_score;
    }
};