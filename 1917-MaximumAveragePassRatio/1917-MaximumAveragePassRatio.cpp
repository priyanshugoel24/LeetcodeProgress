// Last updated: 02/05/2026, 22:38:22
class Solution {
public:
    #define P pair<double,int> 
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<P> pq; // pq[i] = {maxDelta, idx};

        for(int i = 0; i<n; i++){
            double current_PR = (double)classes[i][0]/classes[i][1];
            double new_PR = (double)(classes[i][0]+1)/(classes[i][1]+1);

            double delta = new_PR - current_PR;

            pq.push({delta, i});
        }

        while(extraStudents--){
            auto curr = pq.top();
            pq.pop();

            double delta = curr.first;
            int idx = curr.second;

            classes[idx][0]++; //increment total passing students
            classes[idx][1]++; // increment total students

            double current_PR = (double)classes[idx][0]/classes[idx][1];
            double new_PR = (double)(classes[idx][0]+1)/(classes[idx][1]+1);

            delta = new_PR - current_PR;

            pq.push({delta, idx});


        }

        double result = 0.0;
        for(int i = 0; i<n; i++){
            result += (double)classes[i][0]/classes[i][1];
        }

        return result/n;
        
    }
};