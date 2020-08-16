class Solution {
    public:
        int subarraysWithKDistinct(vector < int > & A, int K) {
            int start = 0;
            int end = 0;
            int uni = 0;
            int step = 0;
            int l = A.size();
            int ans = 0;
            if (l == 0) {
                return 0;
            }

            vector < int > win(l + 1, 0);

            while (true) {
                while (end < l && uni != K) {
                    if (win[A[end]] == 0) {
                        uni++;
                    }
                    ++win[A[end]];
                    end++;
                }
                step = 1;
                while (start != end && win[A[start]] > 1 && uni == K) {
                    --win[A[start]];
                    ++start;
                    ++step;

                }
                if (uni == K) {
                    ans = ans + step;
                }
                while (end < l && win[A[end]] > 0) {
                    if (end < l && win[A[start]] == 1 && A[end] == A[start]) {
                        --win[A[start]];
                        ++start;
                        ++step;
                    }
                    ++win[A[end]];
                    ++end;
                    while (start != end && win[A[start]] > 1) {
                        --win[A[start]];
                        ++start;
                        ++step;
                    }
                    ans = ans + step;
                }

                if (end >= l) {
                    break;
                }

                --uni;
                step = 0;
                --win[A[start]];
                ++start;
            }

            return ans;
        }
};