// Last updated: 02/05/2026, 22:44:40
class LFUCache {
public:

    int total_capacity;
    int size;

    unordered_map<int, list<vector<int>>::iterator> mp; // key -> Address
    map<int, list<vector<int>> > freq; // freq -> {key, val, counter}

    LFUCache(int capacity) {
        total_capacity = capacity;
        size = 0;
    }
    
    void makeMostFrequentlyUsed(int key){

        auto& vec = *(mp[key]);

        int value = vec[1];

        int f = vec[2];

        freq[f].erase(mp[key]);

        if(freq[f].empty()){
            freq.erase(f);
        }

        f++;

        freq[f].push_front({key, value, f});

        mp[key] = freq[f].begin();
    }
    
    int get(int key) {
        
        if(mp.find(key) == mp.end()){
            return -1;
        }

        auto vec = *(mp[key]); // {key, val, counter}

        int value = vec[1];

        makeMostFrequentlyUsed(key);

        return value;
    }
    
    void put(int key, int value) {
        
        if(total_capacity == 0){
            return;
        }

        if(mp.find(key) != mp.end()){
            auto& vec = *(mp[key]);
            vec[1] = value;

            makeMostFrequentlyUsed(key);
        }else if(size < total_capacity){
            size++;

            freq[1].push_front(vector<int>({key, value, 1}));
            mp[key] = freq[1].begin();
        }else{

            auto &list_no = freq.begin()->second;

            int key_to_delete = (list_no.back())[0];

            list_no.pop_back();

            if(list_no.empty()){
                freq.erase(freq.begin()->first);
            }

            freq[1].push_front(vector<int>({key, value, 1}));

            mp.erase(key_to_delete);
            mp[key] = freq[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */