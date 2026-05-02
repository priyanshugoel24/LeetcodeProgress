// Last updated: 02/05/2026, 22:37:25
class Solution {
public:
    bool tasksAssignable(vector<int>& tasks, vector<int>& workers, int pills, int strength, int task){

        int pillsUsed = 0; // no of pills being used
        multiset<int> st(begin(workers), begin(workers) + task); // store best workers with greatest strength in multiset
        
        for(int i = task - 1; i >= 0; i--){
            //strength required to perform current task
            int requiredStrength = tasks[i];
            // strongest worker
            auto it = prev(st.end());

            if(*it >= requiredStrength){
                st.erase(it);
            }else if(pillsUsed >= pills){
                return false;
            }else{
                //find the weakest worker which can do current task using pills
                auto weakestWorkerIt = st.lower_bound(requiredStrength - strength);
                // if no such worker exists
                if(weakestWorkerIt == st.end()){
                    return false;
                }
                st.erase(weakestWorkerIt);
                pillsUsed++;
            }
        }

        return true;

    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        
        int m = tasks.size(), n = workers.size();

        int left = 0; // minimum no of tasks that can be performed
        int right = min(m, n); // maximum no of tasks that can be performed

        //greedily approach assigning tasks to workers
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end(), greater<int>());

        int maxTasksPossible = 0; // resultant no of tasks after assigning them to workers

        while(left <= right){

            int mid = left + (right - left) / 2;

            //helper function to check whether we can do mid no of taksks
            if(tasksAssignable(tasks, workers, pills, strength, mid)){
                //if successful assignment is possible update ans and check if we can perform more tasks
                maxTasksPossible = mid;
                left = mid + 1;
            } else{

                //we can perform less no of tasks
                right = mid - 1;
            }
        }
        
        //return the final result
        return maxTasksPossible;




    }
};