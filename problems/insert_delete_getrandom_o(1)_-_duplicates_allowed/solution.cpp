class RandomizedCollection {
    vector < int > set;
    vector < bool > isPresent;
    unordered_map < int, vector < int >> indexes;
    forward_list < int > freeLocations;
    public:
        /** Initialize your data structure here. */
        RandomizedCollection() {}

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        vector < int > & index = indexes[val];
        if (freeLocations.empty()) {
            index.push_back(set.size());
            set.push_back(val);
            isPresent.push_back(true);
        } else {
            index.push_back(freeLocations.front());
            set[freeLocations.front()] = val;
            isPresent[freeLocations.front()] = true;
            freeLocations.pop_front();
        }
        return index.size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        vector < int > & index = indexes[val];
        if (index.size() == 0) return false;
        int free = index.back();
        index.pop_back();
        freeLocations.push_front(free);
        isPresent[free] = false;
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        while (1) {
            int index = rand() % set.size();
            if (isPresent[index]) return set[index];
        }
        return 0;
    }
};