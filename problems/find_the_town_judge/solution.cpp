class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1) return 1;
        vector<int> vec(n + 1);
        vector<bool> ok(n + 1, true);
        for (auto& v : trust) ok[v[0]] = false;
        for (auto& v : trust) {
            vec[v[1]]++;
            if (vec[v[1]] == n - 1 && ok[v[1]]) return v[1];
        }
        return -1;
    }
};