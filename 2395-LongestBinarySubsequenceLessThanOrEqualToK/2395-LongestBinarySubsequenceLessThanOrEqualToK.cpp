// Last updated: 02/05/2026, 22:36:30
class Solution {
public:
    int longestSubsequence(string s, int k) {
        
        int longest_length = 0;
        int n = s.length();
        long long curr_val = 0;
        int pow = 0;

        for(int i = n - 1; i >= 0; i--){
            
            //we can always include 0's
            if(s[i] == '0'){
                longest_length++;
            }else{

                //if we have 1 if taking it would lead the value to be less than k then no need to skip it

                if(pow < 32){

                    curr_val += (1LL << pow);

                    if(curr_val <= k){
                        longest_length++; // take 1 here
                    }else{
                        curr_val -= (1LL << pow); // skip 1 here
                    }
                }
            }
            pow++;

        }

        return longest_length;
    }
};