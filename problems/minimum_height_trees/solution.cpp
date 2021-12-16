class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        unordered_set<int> tree[n];
        for (auto& e : edges) {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        vector<int> one;
        for (int i = 0; i < n; i++)
            if (tree[i].size() == 1) 
                one.push_back(i);
        while (n > 2) {
            unordered_set<int> curr;
            n -= one.size();
            for (auto& v : one) {
                int val = *tree[v].begin();
                tree[val].erase(v);
                tree[v].erase(val);
                if (tree[val].size() == 1) curr.insert(val);
            }
            one.resize(curr.size());
            copy(curr.begin(), curr.end(), one.begin());
        }
        return one;
    }
};