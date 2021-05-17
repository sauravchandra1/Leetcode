class Solution {
public:
    static bool cmp(const string &a, const string &b) {
        return (a.size() < b.size());
    }
    int longestStrChain(vector<string>& words) {
        int len = words.size();
        sort(words.begin(), words.end(), cmp);
        int last_len = words[len - 1].size();
        vector<int> dp(len, 1);
        auto isFine = [&](string &a, string &b) {
            int l1 = 0, l2 = 0;
            bool done = false;
            while (l1 < a.size() && l2 < b.size()) {
                if (a[l1] == b[l2]) {
                    l1++, l2++;
                } else if (!done) {
                    done = true;
                    l2++;
                } else return false;
            }
            return true;
        };
        int _max = 1, temp;
        for (int i = len - 1; i >= 0; i--) {
            if (words[i].size() == last_len) continue;
            temp = 0;
            for (int j = i + 1; j < len; j++) {
                if (words[j].size() - words[i].size() == 1) {
                    if (isFine(words[i], words[j])) temp = max(temp, dp[j]);
                } else if (words[j].size() - words[i].size() > 1) break;
            }
            dp[i] += temp;
            _max = max(_max, dp[i]);
        }
        return _max;
    }
};