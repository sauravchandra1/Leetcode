class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> vec;
        if (!A.size() || !B.size()) return vec;
        int len_a = A.size();
        int len_b = B.size();
        int i = 0, j = 0;
        int s, e;
        vector<int> a, b;
        while (i < len_a && j < len_b) {
            a = A[i];
            b = B[j];
            s = max(a[0], b[0]);
            e = min(a[1], b[1]);
            if (s <= e) {
                vec.push_back({s, e});
            }
            if (a[1] > b[1]) {
                j++;
            } else if (b[1] > a[1]) {
                i++;
            } else {
                i++;
                j++;
            }
        }
        return vec;
    }
    
};