// Last updated: 02/05/2026, 22:43:59
class Node{
    public:
    int data;
    int row;
    int col;

    Node(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        int mini = INT_MAX, maxi = INT_MIN;
        priority_queue<Node*, vector<Node*>, compare> pq;

        for(int i = 0; i<k; i++){
            int element = nums[i][0];
            maxi = max(maxi, element);
            mini = min(mini, element);
            pq.push(new Node(element, i, 0));
        }

        int start = mini, end = maxi;

        while(!pq.empty()){

            Node* top = pq.top();
            pq.pop();
            mini = top->data;

            if(maxi - mini < end - start){
                start = mini, end = maxi;
            }

            if(top->col + 1 < nums[top->row].size()){
                maxi = max(maxi, nums[top->row][top->col+1]);
                pq.push(new Node(nums[top->row][top->col+1], top->row, top->col+1));
            }
            else{
                break;
            }

        }

        return {start, end};

        
    }
};