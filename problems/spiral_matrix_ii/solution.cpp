class Solution {
    public:
        vector < vector < int >> generateMatrix(int n) {
            vector < vector < int >> ans(n, vector < int > (n, 0));
            int pos_v = 0, pos_h = -1;
            int step_v = n - 1, step_h = n;
            int dir_v = 1, dir_h = 1;
            int count = 0;
            while (step_h) {
                int s_v = 0, s_h = 0;
                while (s_h < step_h) {
                    pos_h += dir_h;
                    ans[pos_v][pos_h] = ++count;
                    s_h++;
                }
                dir_h *= -1;
                step_h -= 1;

                while (s_v < step_v) {
                    pos_v += dir_v;
                    ans[pos_v][pos_h] = ++count;
                    s_v++;
                }
                dir_v *= -1;
                step_v -= 1;
            }

            return ans;
        }
};