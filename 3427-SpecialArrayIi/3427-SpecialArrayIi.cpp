// Last updated: 02/05/2026, 22:33:35
class Solution {
public:
    bool searchViolatingIdx(vector<int>& vi, int start, int end){

        int l = 0, r = vi.size()-1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(vi[mid] < start){
                l = mid+1;
            } else if(vi[mid] > end){
                r = mid-1;                
            }
            else{
                return true;
            }
        }

        return false;
    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size(), m = queries.size();

        vector<int> vi; // violating indices list

        for(int i = 1; i<n; i++){

            if(nums[i]%2 == nums[i-1]%2) vi.push_back(i);
        }

        //vector vi will always be in sorted order

        vector<bool> result(m, false);

        for(int i = 0; i<m; i++){
            int start = queries[i][0], end = queries[i][1];

            bool isViolatingInRange = searchViolatingIdx(vi, start+1, end);

            if(!isViolatingInRange) result[i] = true;
        }

        return result;
        
    }
};