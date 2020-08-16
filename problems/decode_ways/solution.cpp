class Solution {
    public:
        int numDecodings(string s) {
            if (s.size() == 0)
                return 0;
            int ith = 0, i_1 = 1, i_2 = 0;
            int curr = s[s.size() - 1] - '0', prev = 0, val = 0;
            if (curr != 0) {
                ith = 1;
            }
            prev = curr;
            i_2 = i_1;
            i_1 = ith;
            for (int i = s.size() - 2; i >= 0; i--) {
                curr = s[i] - '0';
                if (curr == 0) {
                    ith = 0;
                } else {
                    val = curr * 10 + prev;
                    if (val == 0) {
                        ith = 0;
                    } else {
                        if (val <= 26)
                            ith = i_1 + i_2;
                        else
                            ith = i_1;
                    }
                }
                prev = curr;
                i_2 = i_1;
                i_1 = ith;
            }
            return ith;
        }
};