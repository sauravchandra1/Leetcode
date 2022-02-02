class Solution {
public:
    const int N = 26;
    bool isEqual(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < N; i++) 
            if (a[i] != b[i]) 
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        vector<int> cnt_s(N), cnt_p(N);
        for (auto& v : p) 
            cnt_p[v - 'a']++;
        for (int i = 0; i < p.size(); i++) 
            cnt_s[s[i] - 'a']++;
        vector<int> ans;
        if (isEqual(cnt_s, cnt_p)) 
            ans.push_back(0);
        int l = 0, r = p.size();
        while (r < s.size()) {
            cnt_s[s[l++] - 'a']--;
            cnt_s[s[r++] - 'a']++;
            if (isEqual(cnt_s, cnt_p))
                ans.push_back(l);
        }
        return ans;
    }
};