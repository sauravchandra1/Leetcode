class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        const int N = 26;
        vector<int> vec(N, 0);
        for (auto v : tasks) vec[v - 'A']++;
        int _max = *max_element(vec.begin(), vec.end());
        int ans = tasks.size();
        int tt = (_max - 1) * n;
        bool ok = true;
        for (int i = 0; i < N; i++) {
            if (ok && vec[i] == _max) {
                ok = false;
                continue;
            }
            tt -= min(_max - 1, vec[i]);
        }
        return max(ans, ans + tt);
    }
};