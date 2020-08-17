class Solution {
    public:
        string convert(string s, int numrows) {
            int n = s.length();
            if (numrows == 1)
                return s;
            string t = "";
            int primary = (2 * numrows) - 2;
            int secondary = 0;
            int j, flag;
            for (int i = 0; i < numrows; ++i) {
                j = i;
                flag = 0;
                while (j < n) {
                    if (flag == 0) {
                        flag = 1;
                        if (primary > 0)
                            t += s[j];
                        j = j + primary;
                    } else {
                        flag = 0;
                        if (secondary > 0)
                            t += s[j];
                        j = j + secondary;
                    }
                }
                primary = primary - 2;
                secondary = secondary + 2;
            }
            return t;
        }
};