class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, map<int, string>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (map.find(key) == map.end()) return "";
        auto it = map[key].upper_bound(timestamp);
        if (it == map[key].begin()) {
            return "";
        } else {
            return prev(it, 1)->second;
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */