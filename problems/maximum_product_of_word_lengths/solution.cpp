class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        const int N = 26;
        vector<bool> visited(N, false);
        int ans = 0, lena, lenb;
        for (int i = 0; i < len; i++) {
            for (int k = 0; k < N; k++) visited[k] = false;
            for (auto& c : words[i]) visited[c - 'a'] = true;
            lena = words[i].size();
            for (int j = i + 1; j < len; j++) {
                bool ok = true;
                lenb = words[j].size();
                if (ans >= lena * lenb) continue;
                for (auto& c : words[j]) if (visited[c - 'a']) { ok = false; break; }
                if (ok) ans = max(ans, lena * lenb);
            }
        }
        return ans;
    }
};