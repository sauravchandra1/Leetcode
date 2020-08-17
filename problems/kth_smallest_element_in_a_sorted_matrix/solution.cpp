class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> ans;
        for (auto elem : matrix) {
            for (auto v : elem) {
                ans.push_back(v);
            }
        }
        sort(ans.begin(), ans.end());
        return ans[k - 1];
    }
};