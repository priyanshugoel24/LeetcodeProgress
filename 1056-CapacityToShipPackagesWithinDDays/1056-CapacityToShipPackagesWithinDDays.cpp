// Last updated: 02/05/2026, 22:41:52
class Solution {
public:
    int findMax(vector<int>& arr){
        int maxi = -1e9;

        for(int i = 0; i<arr.size(); i++){
            maxi = max(maxi, arr[i]);
        }

        return maxi;
    }
    int findSum(vector<int>& arr){
        int sum = 0;

        for(int i = 0; i<arr.size(); i++){
            sum += arr[i];
        }

        return sum;
    }

    int noOfDays(vector<int>& weights, int capacity){

        int days = 1, load = 0;

        for(int i = 0; i<weights.size(); i++){
            if(load + weights[i] > capacity){
                days++;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }

        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = findMax(weights), high = findSum(weights);

        while(low <= high){
            
            int mid = (low + high) / 2;

            if(noOfDays(weights, mid) <= days){
                high = mid-1;
            }
            else low = mid+1;
        }

        return low;        
    }
};