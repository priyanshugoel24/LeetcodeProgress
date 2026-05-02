// Last updated: 02/05/2026, 22:39:27
class Solution {
public:
    int findMax(vector<int>& arr){
        int maxi = -1e9;

        for(int i = 0; i<arr.size(); i++){
            maxi = max(maxi, arr[i]);
        }

        return maxi;
    }
    int findMin(vector<int>& arr){
        int mini = 1e9;

        for(int i = 0; i<arr.size(); i++){
            mini = min(mini, arr[i]);
        }

        return mini;
    
    }
    int noofBouqets(vector<int>& bloomDay, int k, int day){

        int flowers = 0;
        int bouqets = 0;

        for(int i = 0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                flowers++;
                
            }
            else{
                bouqets += flowers/k;
                flowers = 0;
            } 
        }

        return bouqets += flowers/k;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n < (long long)m*k) return -1;
              
        int low = findMin(bloomDay), high = findMax(bloomDay);

        while(low <= high){
            int mid = (low + high)/2;

            if(noofBouqets(bloomDay, k, mid) >= m){
                high = mid-1;
            }
            else low = mid+1;
        }

        return low;


        
    }
};