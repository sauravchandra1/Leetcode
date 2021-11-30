class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size(), c;
        if (r) c = matrix[0].size();
        else return 0;
        auto getMax = [&](vector<int>& vec) {
            vec.push_back(0);
            stack<int> stk;
            int ans = 0, tp;
            for (int i = 0; i < vec.size(); i++) {
                while (!stk.empty() && vec[stk.top()] > vec[i]) {
                    tp = stk.top();
                    stk.pop();
                    ans = max(ans, vec[tp] * (stk.empty() ? i : i - stk.top() - 1));
                }
                stk.push(i);
            }
            return ans;
        };
        vector<vector<int>> vec(r, vector<int>(c));
        for (int j = 0; j < c; j++) {
            vec[0][j] = matrix[0][j] - '0';
            for (int i = 1; i < r; i++) {
                vec[i][j] = (matrix[i][j] == '0' ? 0 : vec[i - 1][j] + 1);
            }
        }
        int ans = 0;
        for (int i = 0; i < r; i++) 
            ans = max(ans, getMax(vec[i]));
        return ans;
    }
};