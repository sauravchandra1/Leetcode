class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 2; i <= n; i++) {
            string loop = ans;
            ans.clear();
            for (int j = 0; j < loop.size(); j++) {
                int cnt = 0;
                char ch = loop[j];
                while (j < loop.size() && ch == loop[j]) {
                    cnt++;
                    j++;
                }
                char c = cnt + '0';
                ans += c;
                ans += ch;
                j--;
            }
        }
        return ans;
    }
};