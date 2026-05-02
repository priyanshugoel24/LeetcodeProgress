// Last updated: 02/05/2026, 22:44:34
class Solution {
public:
    int mod = 1e9+7;
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum=0;
        for(auto K:arr){
            sum+=K;
        }
        
        vector<int>dpcur(sum+1);
        vector<int>dpprev(sum+1);
        
    // base  case for i==0
        for(int j=0; j<=sum; j++){
            // take
            int A=j+arr[0];
            int B=sum-A;
            int op1=0;
            if(A-B==d){
                op1=1;
            }
            // donttake
            A=j;
            B=sum-A;
            int op2=0;
            if(A-B==d)op2=1;
            
            dpprev[j]=op1+op2;
        }
        
    // solving 
        for(int i=1; i<n; i++){
            for(int j=0; j<=sum; j++){
                int take = 0;
                if(j + arr[i] <= sum)
                    take=dpprev[j+arr[i]];
                int nottake=dpprev[j];
                dpcur[j]=(take%mod+nottake%mod)%mod;
            }
            dpprev=dpcur;
        }
        
        return dpprev[0];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(), target, nums);


        
    }
};