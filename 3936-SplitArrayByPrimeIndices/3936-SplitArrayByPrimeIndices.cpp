// Last updated: 02/05/2026, 22:32:15
class Solution {
public:
    long long splitArray(vector<int>& nums) {

        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        // finding prime indices using sieve of erasthoenes
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for(int idx = 2 ; idx*idx < n; idx++){

            if(isPrime[idx]){

                for(int j = idx*idx; j < n; j += idx){
                    isPrime[j] = false;
                }
            }
        }

        long long primeIndicesSum = 0LL;
        long long nonPrimeIndicesSum = 0LL;

        for(int i = 0; i < n; i++){

            if(isPrime[i]){
                primeIndicesSum += nums[i];
            }else{
                nonPrimeIndicesSum += nums[i];
            }
        }

        long long diff = abs(primeIndicesSum - nonPrimeIndicesSum);

        return diff;

        
    }
};