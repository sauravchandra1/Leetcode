class Solution {
    public:
        int findJudge(int N, vector<vector<int>>& trust) {
            unordered_map<int, int> mp;
            unordered_map<int, int> cnt;
            for (auto v : trust) {
                mp[v[0]]++; 
                cnt[v[1]]++;
            }
            vector<int> ans;
            for (int i = 1; i <= N; i++) {
                if (mp.count(i) == 0 && cnt[i] == N - 1) ans.push_back(i);
            }
            if (ans.size() == 1) return ans[0];
            return -1;
        }
};