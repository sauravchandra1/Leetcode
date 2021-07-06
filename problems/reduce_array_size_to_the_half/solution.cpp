class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int len = arr.size();
        vector<int> count(1e5 + 1, 0);
        for (auto& v : arr) count[v]++;
        sort(count.begin(), count.end(), greater<int>());
        int val = 0;
        for (int i = 0; i < 1e5 + 1; i++) {
            if (val >= len / 2) return i;
            val += count[i];
        }
        return len;
    }
};