class Solution {
    public:
        struct hash_pair {
            template < class T1, class T2 >
                size_t operator()(const pair < T1, T2 > & p) const {
                    auto hash1 = hash < T1 > {}(p.first);
                    auto hash2 = hash < T2 > {}(p.second);
                    return hash1 ^ hash2;
                }
        };
    int maxPoints(vector < vector < int >> & points) {
        typedef pair < int, int > pii;
        int n = points.size(), ans = n == 0 ? 0 : 1;
        unordered_map < pii, int, hash_pair > m;
        sort(points.begin(), points.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && points[i][0] == points[i - 1][0] && points[i][1] == points[i - 1][1])
                continue;
            m.clear();
            int same = 1;
            for (int j = i + 1; j < n; j++) {
                int y = points[i][1] - points[j][1];
                int x = points[i][0] - points[j][0];
                if (x == 0 && y != 0) {
                    m[pii {
                        INT_MAX,
                        0
                    }]++;
                    ans = max(m[pii {
                        INT_MAX,
                        0
                    }] + same, ans);
                    continue;
                }
                if (x == 0 && y == 0) {
                    same++;
                    ans = max(same, ans);
                } else {
                    int g = __gcd(y, x);
                    m[pii {
                        y / g, x / g
                    }]++;
                    ans = max(m[pii {
                        y / g, x / g
                    }] + same, ans);
                }
            }
        }
        return ans;
    }
};