class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        auto up = [&](string str, int i) {
            if (str[i] == '9') str[i] = '0';
            else str[i] += 1;
            return str;
        };
        auto down = [&](string str, int i) {
            if (str[i] == '0') str[i] = '9';
            else str[i] -= 1;
            return str;
        };
        unordered_map<string, bool> mp, seen;
        for (auto& s : deadends) mp[s] = true;
        queue<pair<string, int>> Q;
        int c = 0;
        if (mp.count(target) == 0) Q.push({target, 0});
        while (!Q.empty()) {
            string str = Q.front().first;
            int d = Q.front().second;
            Q.pop();
            if (str == "0000") return d;
            seen[str] = true;
            for (int i = 0; i < 4; i++) {
                string tt = up(str, i);
                if (seen.count(tt) == 0 && mp.count(tt) == 0) {
                    Q.push({tt, d + 1});
                    seen[tt] = true;
                }
            }
            for (int i = 0; i < 4; i++) {
                string tt = down(str, i);
                if (seen.count(tt) == 0 && mp.count(tt) == 0) {
                    Q.push({tt, d + 1});
                    seen[tt] = true;
                }
            }
        }
        return -1;
    }
};