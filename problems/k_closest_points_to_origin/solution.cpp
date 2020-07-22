class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](const vector<int>& a, 
                                              const vector<int>& b) {
            int val1 = a[0] * a[0] + a[1] * a[1];
            int val2 = b[0] * b[0] + b[1] * b[1];
            return (val1 < val2);
        });
        points.resize(K);
        return points;
    }
};