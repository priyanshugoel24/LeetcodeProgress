// Last updated: 02/05/2026, 22:44:02
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int total_tasks = tasks.size();

        if(n == 0){
            return total_tasks;
        }

        vector<int> labelFreq(26, 0);
        for(auto& task : tasks){

            int labelIdx = task - 'A';

            labelFreq[labelIdx]++;
        }

        sort(begin(labelFreq), end(labelFreq));

        int maxFreq = labelFreq[25];
        
        int blanks = maxFreq - 1;
        int idle_slots = blanks * n;

        for(int i = 24; i >= 0; i--){

            int currLabelFreq = labelFreq[i];

            idle_slots -= min(currLabelFreq, blanks);
        }

        int minCPUIntervals = total_tasks + ((idle_slots > 0) ? idle_slots : 0);

        return minCPUIntervals;
    }
};