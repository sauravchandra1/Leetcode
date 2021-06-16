class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        function<void(string, int, int)> dfs = [&](string str, int sum, int idx) {
            if (sum < 0 || sum > n) return;
            if (idx == 2 * n) {
                if (sum == 0)
                    ans.push_back(str);
                return;
            }
            dfs(str + '(', sum + 1, idx + 1);
            dfs(str + ')', sum - 1, idx + 1);
        };
        dfs("", 0, 0);
        return ans;
    }
};