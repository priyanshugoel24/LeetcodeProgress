// Last updated: 02/05/2026, 22:42:42
class Solution {
public:
    unordered_set<string> st;

    void buildSet(){

        for(int p = 0; p <= 29; p++){

            string str = to_string(1 << p);
            sort(begin(str), end(str));
            st.insert(str);
        }
    }
    bool reorderedPowerOf2(int n) {
        
        buildSet();
        
        string s = to_string(n);

        sort(begin(s), end(s));

        return st.count(s);
    }
};