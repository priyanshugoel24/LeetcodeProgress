// Last updated: 02/05/2026, 22:38:07
class FindSumPairs {
public:
    vector<int> arr1;
    vector<int> arr2;

    unordered_map<int, int> arr2_freq;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        
        arr1 = nums1;
        arr2 = nums2;

        for(int i = 0; i < arr2.size(); i++){
            arr2_freq[arr2[i]]++;
        }
    }
    
    void add(int index, int val) {
        
        int curr_val = arr2[index];
        int new_val = curr_val + val;

        arr2[index] = new_val;

        arr2_freq[curr_val] -= 1;
        arr2_freq[new_val] += 1;
    }
    
    int count(int tot) {
        
        int total_pairs = 0;

        for(int i = 0; i < arr1.size(); i++){

            int val1 = arr1[i];

            int required = tot - val1;

            if(arr2_freq.find(required) != arr2_freq.end()){

                total_pairs += arr2_freq[required];
            }

        }

        return total_pairs;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */