class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp, p;
        for (auto v : arr1) {
            mp[v]++;
        }
        vector<int> ans;
        for (auto v : arr2) {
            while (mp[v]--) {
                ans.push_back(v);
            }
            p[v] = 1;
        }
        vector<int> res;
        for (auto v : arr1) {
            if (p.count(v) == 0) {
                res.push_back(v);
            }
        }
        sort(res.begin(), res.end());
        for (auto v : res) ans.push_back(v);
        return ans;
    }
};