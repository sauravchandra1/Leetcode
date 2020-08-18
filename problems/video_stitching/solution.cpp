class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int len = clips.size();
        if (len == 1) {
            if (clips[0][0] == 0 && clips[0][1] >= T) return 1;
            else return -1;
        }
        sort(clips.begin(), clips.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0]) return (a[1] > b[1]);
            return (a[0] < b[0]);
        });
        int ans = 1, s = clips[0][0], e = clips[0][1];
        if (s != 0) return -1;
        int m = 0;
        for (int i = 1; i < clips.size(); i++) {
            auto v = clips[i];
            if (s <= v[0] && e >= v[1]) continue;
            if (v[0] <= e) {
                m = max(m, v[1]);
            } else {
                if (m > e) {
                    e = m;
                    ans++;
                }
                m = 0;
            }
            if (e >= T) return ans;
        }
        if (m > e) {
            e = m;
            ans++;
        }
        if (e < T) return -1;
        return ans;
    }
};