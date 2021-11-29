class DSU {
    vector<int> rank, par;
public:
    DSU(int n) : rank(n), par(n) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) {
        if (x == par[x]) return x;
        par[x] = find(par[x]);
        return par[x];
    }
    void uni(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) return;
        if (rank[x_root] > rank[y_root]) par[y_root] = x_root;
        else if (rank[x_root] < rank[y_root]) par[x_root] = y_root;
        else {
            rank[x_root]++;
            par[y_root] = x_root;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int len = accounts.size();
        DSU d(len);
        vector<vector<string>> ans(len);
        unordered_map<string, int> mp, seen;
        for (int i = 0; i < len; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mp.count(accounts[i][j])) {
                    int idx = mp[accounts[i][j]];
                    idx = d.find(idx);
                    d.uni(idx, i);
                } else mp[accounts[i][j]] = i;
            }
        }
        for (int i = 0; i < len; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mp[accounts[i][j]] < i || seen.count(accounts[i][j]) > 0) continue;
                seen[accounts[i][j]] = 1;
                int idx = mp[accounts[i][j]];
                idx = d.find(idx);
                if (!ans[idx].size()) ans[idx].push_back(accounts[i][0]);
                ans[idx].push_back(accounts[i][j]);
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i].size() > 0) 
                sort(ans[i].begin() + 1, ans[i].end());
            else {
                swap(ans[i], ans[ans.size() - 1]);
                ans.pop_back();
                i--;
            }
        }
        return ans;
    }
};