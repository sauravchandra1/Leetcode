class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> pos, neg, zero;
        unordered_map<int, int> pp, nn;
        for (auto v : nums) {
            if (v == 0) zero.push_back(v);
            else if (v > 0) {
                pos.push_back(v);
                pp[v]++;
            }
            else { 
                neg.push_back(v);
                nn[v]++;
            }
        }
        bool ok = false;
        if (zero.size() > 0) ok = true;
        sort(neg.begin(), neg.end(), greater<int>());
        sort(pos.begin(), pos.end());
        vector<vector<int>> ans;
        set<vector<int>> res;
        vector<int> tt;
        if (zero.size() >= 3) ans.push_back({0, 0, 0});
        for (auto p : pos) {
            for (auto n : neg) {
                if (p == -n && ok) {
                    tt.clear();
                    tt.push_back(n);
                    tt.push_back(0);
                    tt.push_back(p);
                    if (res.find(tt) == res.end()) res.insert(tt);
                } else if (p < -n) {
                    break;
                } else {
                    int r = p + n;
                    r = -r;
                    if (r == n) {
                        if (nn[r] >= 2) {
                            tt.clear();
                            tt.push_back(r);
                            tt.push_back(r);
                            tt.push_back(p);
                            if (res.find(tt) == res.end()) res.insert(tt);
                        }
                    } else {
                        if (nn[r] >= 1) {
                            tt.clear();
                            tt.push_back(min(r, n));
                            tt.push_back(max(r, n));
                            tt.push_back(p);
                            if (res.find(tt) == res.end()) res.insert(tt);
                        }
                    }
                }
            }
        }
         for (auto n : neg) {
            for (auto p : pos) {
                if (p == -n && ok) {
                    tt.clear();
                    tt.push_back(n);
                    tt.push_back(0);
                    tt.push_back(p);
                    if (res.find(tt) == res.end()) res.insert(tt);
                } else if (p > -n) {
                    break;
                } else {
                    int r = p + n;
                    r = -r;
                    if (r == p) {
                        if (pp[r] >= 2) {
                            tt.clear();
                            tt.push_back(n);
                            tt.push_back(r);
                            tt.push_back(r);
                            if (res.find(tt) == res.end()) res.insert(tt);
                        }
                    } else {
                        if (pp[r] >= 1) {
                            tt.clear();
                            tt.push_back(n);
                            tt.push_back(min(r, p));
                            tt.push_back(max(r, p));
                            if (res.find(tt) == res.end()) res.insert(tt);
                        }
                    }
                }
            }
        }
        for (auto v : res) ans.push_back(v);
        return ans;
    }
};