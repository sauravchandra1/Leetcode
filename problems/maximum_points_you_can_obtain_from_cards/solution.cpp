class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        vector<int> prefix(len + 1, 0);
        int n = len - k;
        for (int i = 0; i < len; i++) prefix[i + 1] = prefix[i] + cardPoints[i];
        int _min = INT_MAX;
        for (int i = n; i <= len; i++) _min = min(_min, prefix[i] - prefix[i - n]);
        return prefix[len] - _min;
    }
};