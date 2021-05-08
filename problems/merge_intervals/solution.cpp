class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> vec;
        int len = intervals.size();
        for (int i = 0; i < len; i++) {
            vec.push_back({intervals[i][0], intervals[i][1]});
        }
        sort(vec.begin(), vec.end());
        vector<vector<int>> ans;
        vector<int> temp(2);
        int s = -1, e;
        for (int i = 0; i < len; i++) {
            if (s == -1) {
                s = vec[i].first;
                e = vec[i].second;
            } else {
                if (vec[i].first <= e) {
                    e = max(e, vec[i].second);
                } else {
                    temp[0] = s;
                    temp[1] = e;
                    ans.push_back(temp);
                    s = -1;
                    i--;
                }
            }
        }
        if (s != -1) {
            temp[0] = s;
            temp[1] = e;
            ans.push_back(temp);
        }
        return ans;
    }
};