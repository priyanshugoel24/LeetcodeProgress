// Last updated: 02/05/2026, 22:38:56
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        set<pair<int, pair<int,int> > > st;
        st.insert({0, {0,0}});
        dist[0][0] = 0;

        vector<pair<int,int>> directions = { {-1,0}, {0,-1} ,{1,0}, {0,1}};
        
        while(!st.empty()){
            auto top = *(st.begin());
            int effort = top.first;
            int row = top.second.first;
            int col = top.second.second;
            st.erase(top);

            if(effort > dist[row][col]) continue;
            if(row == n-1 && col == m-1) return effort;

            for(auto dir : directions){
                int nRow = row + dir.first;
                int nCol = col + dir.second;

                if(nRow >= 0 && nRow < n && nCol >=0 && nCol < m){

                    int newEffort = max(effort, abs(heights[nRow][nCol] - heights[row][col]));

                    if(newEffort < dist[nRow][nCol]){

                        auto record = st.find({dist[nRow][nCol], {nRow, nCol}});

                        if(record != st.end()){
                            st.erase(record);
                        }

                        dist[nRow][nCol] = newEffort;
                        st.insert({newEffort, {nRow, nCol}});

                    }

                    
                }

            }
        }

        return -1;
        
    }
};