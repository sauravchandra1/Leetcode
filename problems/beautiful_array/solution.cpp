class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> vec;
        for (int i = 1; i <= n; i += 2) vec.push_back(i);
        function<void(int, int)> dfs = [&](int l, int r) {
            if (r - l <= 1) return;
            vector<int> tmp;
            for (int i = l; i <= r; i += 2) tmp.push_back(vec[i]);
            for (int i = l + 1; i <= r; i += 2) tmp.push_back(vec[i]);
            for (int i = 0; i < tmp.size(); i++) vec[i + l] = tmp[i];
            int m = (l + r) / 2;
            dfs(l, m);
            dfs(m + 1, r);
        };
        dfs(0, vec.size() - 1);
        int len = vec.size();
        for (int i = 0; i < len; i++) 
            if (vec[i] + 1 <= n) vec.push_back(vec[i] + 1);
        return vec;
    }
};