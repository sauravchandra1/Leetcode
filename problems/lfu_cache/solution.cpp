class LFUCache {
public:
    unordered_map<int, int> cache, freq, l;
    map<pair<int,int>, int> m1;  
    int cap;
    int lvl = 0;
    LFUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        lvl++;
        if (cache.find(key) != cache.end()) {
            m1.erase({freq[key], l[key]});
            m1[{freq[key] + 1, lvl}] = key;
            l[key] = lvl;
            freq[key] += 1;
            return cache[key];
        }
        return -1;
    }
    void put(int key, int value) {
        lvl++;
        if (cache.find(key) != cache.end()) {
                m1.erase({freq[key], l[key]});
                m1[{freq[key] + 1, lvl}] = key;
                l[key] = lvl;
                freq[key] += 1;
                cache[key] = value;
        } else if (cache.size() < cap) {
                m1[{1, lvl}] = key;
                freq[key] = 1;
                l[key] = lvl;
                cache[key] = value;
        } else if (m1.size() != 0) {
                pair<pair<int, int>,int>p1 = *m1.begin();     
                cache.erase(p1.second);
                m1.erase(m1.begin());
                m1[{1, lvl}] = key;
                freq[key] = 1;
                l[key] = lvl;
                cache[key] = value;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */