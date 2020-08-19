class Solution {
    public:
        int maxHistogram(vector < int > & heights) {
            int n = heights.size(), maxArea = 0;
            stack < pair < int, int >> s_nsl, s_nsr;
            s_nsl.push({
                INT_MIN,
                -1
            });
            s_nsr.push({
                INT_MIN,
                n
            });
            vector < int > nsl(n), nsr(n);

            for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
                while (!s_nsl.empty() && heights[i] <= s_nsl.top().first)
                    s_nsl.pop();
                nsl[i] = abs(i - s_nsl.top().second);
                s_nsl.push({
                    heights[i],
                    i
                });

                while (!s_nsr.empty() && heights[j] <= s_nsr.top().first)
                    s_nsr.pop();
                nsr[j] = abs(j - s_nsr.top().second);
                s_nsr.push({
                    heights[j],
                    j
                });
            }

            for (int i = 0; i < n; i++) {
                maxArea = max(maxArea, (nsr[i] + nsl[i] - 1) * heights[i]);
            }

            return maxArea;
        }

    int maximalRectangle(vector < vector < char >> & matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size(), maxArea = 0;

        vector < int > heights(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') heights[j] = 0;
                else heights[j] += 1;
            }
            maxArea = max(maxArea, maxHistogram(heights));
        }

        return maxArea;
    }
};