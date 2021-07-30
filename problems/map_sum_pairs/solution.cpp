class MapSum {
public:
    /** Initialize your data structure here. */
    map<string, int> mp, word;
    MapSum() {
        mp.clear();
        word.clear();
    }
    
    void insert(string key, int val) {
        string str;
        int v = 0;
        if (word.count(key))
            v = -word[key];
        for (int i = 0; i < key.size(); i++) {
            str += key[i];
            mp[str] += (val + v);
        }
        word[key] = val;
    }
    
    int sum(string prefix) {
        return mp[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */