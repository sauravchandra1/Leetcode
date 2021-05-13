class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<pair<string, string>> vec;
        int len = s.size();
        vector<string> temp;
        function<void(int,int)> dfs = [&](int l, int r) {
            string S;
            temp.clear();
            if (l == r) {
                S += s[l];
                temp.push_back(S);
                return;
            }
            for (int i = l; i <= r; i++) S += s[i];
            if (S.size() > 1 && S[0] != '0') temp.push_back(S);
            int len = S.size();
            string s1, s2;
            for (int i = 1; i < len; i++) {
                s1 = s2 = "";
                for (int j = 0; j < i; j++) s1 += S[j];
                for (int j = i; j < len; j++) s2 += S[j];
                bool is_digit = true;
                if (s2[s2.size() - 1] == '0') is_digit = false;
                if (is_digit && (s1.size() == 1 || s1.size() > 1 && s1[0] != '0')) {
                    s1 = s1 + '.' + s2;
                    temp.push_back(s1);
                }
            }
        };
        vector<string> ans;
        for (int i = 2; i < len - 1; i++) {
            dfs(1, i - 1);
            vector<string> temp1(temp);
            dfs(i, len - 2);
            for (int l = 0; l < temp1.size(); l++) {
                for (int m = 0; m < temp.size(); m++) {
                    string t = "(" + temp1[l] + ", " + temp[m] + ")";
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};