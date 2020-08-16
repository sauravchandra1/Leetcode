class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int s, e;
        vector<vector<int>> ans;
        bool ok = false;
        int _n = newInterval.size();
        if (_n == 0) return intervals;
        int len = intervals.size();
        if (len == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        for (auto v : intervals) {
            if (!ok) {
                s = max(v[0], newInterval[0]);
                e = min(v[1], newInterval[1]);
                if (s <= e) {
                    ok = true;
                    v[0] = min(v[0], newInterval[0]);
                    v[1] = max(v[1], newInterval[1]);
                } else if (newInterval[1] < v[0]) {
                    ans.push_back(newInterval);
                    ok = true;
                }
                ans.push_back(v);
            } else {
                vector<int> tt = ans.back();
                s = max(v[0], tt[0]);
                e = min(v[1], tt[1]);
                if (s <= e) {
                    v[0] = min(v[0], tt[0]);
                    v[1] = max(v[1], tt[1]);
                    ans.pop_back();
                    ans.push_back(v);
                } else ans.push_back(v);
            }
        }
        if (ok == false) ans.push_back(newInterval);
        return ans;
    }
};