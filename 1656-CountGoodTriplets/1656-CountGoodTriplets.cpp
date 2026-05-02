// Last updated: 02/05/2026, 22:39:18
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        
        int n = arr.size();
        int goodTriplets = 0; // total no of good triplets in the array

        for(int i = 0; i < n; i++){
            
            for(int j = i + 1; j < n; j++){

                if(abs(arr[i] - arr[j]) <= a){ // good triplet possible

                    for(int k = j + 1; k < n; k++){

                        if((abs(arr[j] - arr[k]) <= b) &&  abs(arr[i] - arr[k]) <= c){
                            //good triplet found
                            goodTriplets++;
                        }
                    }
                }
            }
        }

        return goodTriplets;
    }
};