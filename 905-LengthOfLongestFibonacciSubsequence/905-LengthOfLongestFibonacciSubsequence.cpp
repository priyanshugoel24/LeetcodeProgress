// Last updated: 02/05/2026, 22:42:41
class Solution {
public:
    int bs(vector<int>& arr, int t){
       int l = 0, r = arr.size() -1, mid = 0;

       while( l <= r){
        mid = l + (r-l) / 2;

        if(arr[mid] > t){
            r = mid - 1;
        } else if(arr[mid] < t){
            l = mid + 1;
        } else return mid;
       }

       return -1;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        const int n = arr.size();
        int first = 0, second = 0;
        int ans = 0;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                first = arr[i];
                second = arr[j];

                int cnt = 2;
                bool flag = true;

                while(flag){
                    int idx = bs(arr, first + second);

                    if(idx != -1){
                        first = second;
                        second = arr[idx];
                        cnt++;
                    } else{
                        flag = false;
                    }
                }
                ans = max(ans, cnt);
            }
            
        }

        return (ans > 2) ? ans : 0;
    }
};