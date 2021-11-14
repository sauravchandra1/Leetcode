class CombinationIterator {
public:
    bool finish;
    vector<int> ptr;
    string str, ans;
    CombinationIterator(string characters, int combinationLength) {
        str = characters;
        finish = false;
        ptr.resize(combinationLength);
        iota(ptr.begin(), ptr.end(), 0);
    }
    
    void getNext() {
        int l1 = str.size() - 1, l2 = ptr.size() - 1;
        while (ptr[l2] == l1) {
            l2--, l1--;
            if (l2 < 0) {
                finish = true;
                return;
            }
        }
        ptr[l2]++;
        for (int i = l2 + 1; i < ptr.size(); i++) ptr[i] = ptr[i - 1] + 1;
    }
    string next() {
        string ans;
        for (auto& i : ptr) ans += str[i];
        getNext();
        return ans;
    }
    
    bool hasNext() {
        return !finish;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */