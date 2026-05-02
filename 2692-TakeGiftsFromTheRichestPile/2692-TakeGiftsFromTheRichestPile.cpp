// Last updated: 02/05/2026, 22:35:12
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

      priority_queue<int> pq(gifts.begin(), gifts.end());
      long long ans = 0;

      while(k--){
        int gift = pq.top();     

        pq.pop();
        pq.push(sqrt(gift));
      }

      while(!pq.empty()){
        ans += pq.top();
        pq.pop();
      }

      return ans;

      
        
    }
};