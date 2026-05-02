// Last updated: 02/05/2026, 22:34:42
class Solution {
public:
    #define P pair<int,int>
    long long continuousSubarrays(vector<int>& nums) {

        int n = nums.size();

        priority_queue<P, vector<P>, greater<P>> minHeap;
        priority_queue<P> maxHeap;

        int l = 0, r=0;
        long long count = 0;

        while(r < n){
            minHeap.push({nums[r], r});
            maxHeap.push({nums[r], r});

            while(abs(maxHeap.top().first - minHeap.top().first) > 2){
                l++;
                while(!maxHeap.empty() && maxHeap.top().second < l) maxHeap.pop();
                while(!minHeap.empty() && minHeap.top().second < l) minHeap.pop();
            }

            count += r-l+1;
            r++;
        }
        return count;
        
    }
};