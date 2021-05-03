class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.size();
        vector<vector<bool>> 
            palindrome(len + 1, vector<bool> (len + 1, false));
        
        function<bool(string)> isPalin = [&](string str) {
            int l = 0, r = str.size() - 1;
            while (l < r) {
                if (str[l] != str[r]) return false;
                l++, r--;
            }
            return true;
        };
        
        string temp;
        for (int i = 0; i < len; i++) {
            temp = "";
            for (int j = i; j < len; j++) {
                temp += s[j];
                palindrome[i][j] = isPalin(temp);
            }
        }
        vector<vector<string>> ans;
        vector<string> vec;
        function<void(int)> dfs = [&](int idx) {
            if (idx == len) {
                ans.push_back(vec);
                return;
            }
            string temp;
            for (int i = idx; i < len; i++) {
                temp += s[i];
                if (palindrome[idx][i]) {
                    vec.push_back(temp);
                    dfs(i + 1);
                    vec.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};