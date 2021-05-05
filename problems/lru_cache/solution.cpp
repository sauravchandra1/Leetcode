class LRUCache {
public:
    unordered_map<int, int> timer, p;
    map<int, int> mp;
    int currTimer, cap;
    LRUCache(int capacity) {
        currTimer = 0;
        cap = capacity;
    }
    
    int get(int key) {
        currTimer++;
        if (p.count(key) > 0) {
            int t = timer[key];
            mp.erase(t);
            mp[currTimer] = key;
            timer[key] = currTimer;
            return p[key];
        } return -1;
    }
    
    void put(int key, int value) {
        currTimer++;
        if (p.count(key) > 0) {
            p[key] = value;
            int t = timer[key];
            mp.erase(t);
        } else if (mp.size() == cap) {
            auto it = mp.begin();
            int t = it->first, k = it->second;
            p.erase(k);
            timer.erase(k);
            mp.erase(t);
        } 
        timer[key] = currTimer;
        p[key] = value;
        mp[currTimer] = key;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */