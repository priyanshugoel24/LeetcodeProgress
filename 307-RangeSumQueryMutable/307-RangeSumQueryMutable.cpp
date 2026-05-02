// Last updated: 02/05/2026, 22:45:38
class NumArray {
public:
    int n;
    vector<int> arr;
    vector<int> segmentTree;
    NumArray(vector<int>& nums) {
        
        n = nums.size();
        arr = nums;

        segmentTree.resize(4*n);

        buildSegmentTree(0, 0, n - 1);
    }
    
    void update(int index, int val) {

        updateQuery(0, 0, n - 1, index, val);

    }
    
    int sumRange(int left, int right) {
        
        return sumQuery(0, 0, n - 1, left, right);
    }

    void buildSegmentTree(int i, int l, int r){

        //base case : leaf node
        if(l == r){
            segmentTree[i] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegmentTree(2*i + 1, l, mid);
        buildSegmentTree(2*i + 2, mid + 1, r);

        segmentTree[i] = segmentTree[2*i + 1] + segmentTree[2*i + 2];
    }

    void updateQuery(int i, int l, int r, int idx, int val){

        if(l == r){
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if(idx <= mid){

            updateQuery(2*i + 1, l, mid, idx, val);
        }else{

            updateQuery(2*i + 2, mid + 1, r, idx, val);
        }

        segmentTree[i] = segmentTree[2*i + 1] + segmentTree[2*i + 2];
    }

    int sumQuery(int i, int l, int r, int start, int end){
        
        // // case : leaf node
        // if(l == r){
        //     return segmentTree[i];
        // }

        // case : out of range
        if(l > r || r < start || l > end){
            return 0;
        }

        // case : perfectly within range
        if(l >= start && r <= end){

            return segmentTree[i];
        }

        int sum = 0;

        int mid = l + (r-l)/ 2;

        int sum_left = sumQuery(2*i + 1, l, mid, start, end);
        int sum_right = sumQuery(2*i + 2, mid + 1, r, start, end);

        sum = sum_left + sum_right;

        return sum;

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */