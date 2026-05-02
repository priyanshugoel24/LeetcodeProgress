// Last updated: 02/05/2026, 22:36:57
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        
        long long len = nums.size(); // size of the array
        long long n = len / 3; // elements to remove

        vector<long long> prefixSum(len); // stores prefixsum at index i
        vector<long long> suffixSum(len); // stores suffix sum at index i

        priority_queue<int> maxHeap; // to store n min elements in first half of array
        priority_queue<int, vector<int>, greater<int>> minHeap; // to store n max elements in second half of array

        // finding min elements for first half
        long long preSum = 0;
        for(long long i = 0; i < 2*n; i++){

            preSum += nums[i];
            maxHeap.push(nums[i]);

            if(maxHeap.size() > n){
                preSum -= maxHeap.top();
                maxHeap.pop();
            }

            if(maxHeap.size() == n){
                prefixSum[i] = preSum;
            }
        }

        //finding max elements for second half
        long long suffSum = 0;
        for(long long i = len - 1; i >= n; i--){

            suffSum += nums[i];
            minHeap.push(nums[i]);

            if(minHeap.size() > n){
                suffSum -= minHeap.top();
                minHeap.pop();
            }

            if(minHeap.size() == n){
                suffixSum[i] = suffSum;
            }
        }

        long long minDiff = LLONG_MAX;

        for(long long i = n - 1; i < 2*n; i++){

            long long curr_diff = prefixSum[i] - suffixSum[i + 1];

            minDiff = min(minDiff, curr_diff);
        }


        return minDiff;
        
    }
};