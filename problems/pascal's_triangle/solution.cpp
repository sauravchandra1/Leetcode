class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> res;
        int last;
        for (int i = 0; i < numRows; i++) {
            res.clear();
            res.push_back(1);
            if (ans.size() == 0) {
                ans.push_back(res);
                continue;
            } else if (ans.size() == 1) {
                res.push_back(1);
                ans.push_back(res);
                continue;
            }
            last = 1;
            for (int j = 1; j < ans.back().size(); j++) {
                res.push_back(last + ans.back()[j]);
                last = ans.back()[j];
            }
            res.push_back(1);
            ans.push_back(res);
        }
        return ans;
    }
};