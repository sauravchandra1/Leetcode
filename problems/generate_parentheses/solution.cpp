class Solution {
    public:
        vector < string > ans;
    void recur(int c, int c1, int n, string & s) {
        if (c1 == n && c == 0)
        {
            ans.push_back(s);
            return;
        }
        s += "(";
        if (c1 < n)
            recur(c + 1, c1 + 1, n, s); 
        s[s.length() - 1] = ')';
        if (c > 0)
            recur(c - 1, c1, n, s);    
        s = s.substr(0, s.length() - 1);
    }
    vector < string > generateParenthesis(int n) {
        string s = "";
        recur(0, 0, n, s);
        return ans;
    }
};