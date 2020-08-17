class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.size();
        vector<queue<int>> vec(10);
        for (int i = 0; i < len; i++) {
            int d = num[i] - '0';
            vec[d].push(i);
        }
        vector<pair<int, int>> res;
        auto go = [&](int d, int idx) {
            for (int i = 0; i < d; i++) {
                if (!vec[i].empty() && vec[i].front() - idx <= k) {
                    return vec[i].front();
                }
            }
            return -1;
        };
        auto clean = [&](int idx) {
            for (int i = 0; i < 10; i++) {
                while (!vec[i].empty() && vec[i].front() <= idx) vec[i].pop();
            }
        };
        for (int i = 0; i < len; i++) {
            clean(i);
            if (k == 0) break;
            int d = num[i] - '0';
            int id = go(d, i);
            if (id != -1) {
                res.push_back({i, id - 1});
                k -= id - i;
                i = id - 1;
            }
        }
        for (auto p : res) {
            for (int i = p.first; i <= p.second; i++) {
                num[i] = '*';
            }
        }
        string ans;
        for (int i = 0; i < len; i++) {
            if (num[i] != '*') ans += num[i];
        }
        while (k--) ans.pop_back();
        int cnt = 0;
        for (auto v : ans) {
            if (v != '0') break;
            cnt++;
        }
        if (ans.size() == 0) return "0";
        if (cnt == ans.size()) return "0";
        return ans.substr(cnt);
    }
};