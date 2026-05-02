// Last updated: 02/05/2026, 22:42:22
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        stack<int> s1, s2;
        int n = arr.size();
        vector<int> pre_smaller(n), next_smaller(n);

        for(int i = 0; i<n; i++){

            next_smaller[i] = n-i-1;
            pre_smaller[i] = i;
        }

        for(int i = 0; i<n; i++){

            while(!s1.empty() && arr[s1.top()] > arr[i]){

                next_smaller[s1.top()] = i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }

        for(int i = n-1; i>=0; i--){

            while(!s2.empty() && arr[s2.top()] >= arr[i]){

                pre_smaller[s2.top()] = s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }

        long long ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            ans=(ans+(arr[i]*(long long)(next_smaller[i]+1)*(pre_smaller[i]+1))%mod)%mod;
        }
        return (int)ans;
    }
};