// Last updated: 02/05/2026, 22:39:52
class Solution {
public:
    int n2;
    string dfs(string prefix, int n, int k){
        if(n == 0) return prefix;

        for(char c = 'a'; c <= 'c'; c++){
            if(!prefix.empty() && c == prefix.back()) continue;
            int cnt = (1 << n2 - prefix.length() - 1);
            if(cnt >= k) return dfs(prefix + c, n-1, k);
            else k -= cnt;
        }

        return "";
    }
    string getHappyString(int n, int k) {
        n2 = n;
        return dfs("", n, k);
        
    }
};