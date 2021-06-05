class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int mod = 1e9 + 7;
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) vec.push_back({efficiency[i], speed[i]});
        sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, ans = 0;
        for (int i = 0; i < k; i++) {
            pq.push(vec[i].second);
            sum += vec[i].second;
            ans = max(ans, sum * vec[i].first);
        }
        for (int i = k; i < n; i++) {
            int sp = vec[i].second;
            if (pq.top() < sp) {
                sum -= pq.top();
                sum += sp;
                pq.pop();
                pq.push(sp);
                ans = max(ans, sum * vec[i].first);
            }
        }
        return ans % mod;
    }
};