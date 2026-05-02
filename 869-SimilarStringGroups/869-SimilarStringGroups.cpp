// Last updated: 02/05/2026, 22:42:55
class Solution {
public:
    class DSU{
        public:
        vector<int> parent;
        int size;

        
        DSU(int n){

            parent.resize(n);
            size = n;

            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }

        int findPar(int x){

            if(parent[x] != x){
                parent[x] = findPar(parent[x]);
            }

            return parent[x];
        }

        void Union(int x, int y){

            int par_x = findPar(x);
            int par_y = findPar(y);

            if(par_x == par_y) return;

            parent[par_x] = par_y;
            size--;
        }
    };

    bool isSimilar(string a, string b){

        int n = a.length();

        int differ = 0;

        for(int i = 0; i < n; i++){

            if(a[i] != b[i]){
                differ++;
            }
        }

        return (differ <= 2);
    }
    int numSimilarGroups(vector<string>& strs) {
        
        int words = strs.size();

        int n = strs[0].length();

        DSU dsu(words);

        for(int i = 0; i < words; i++){

            for(int j = i; j < words; j++){

                if(isSimilar(strs[i], strs[j])){
                    dsu.Union(i, j);
                }
            }
        }

        return dsu.size;


        
    }
};