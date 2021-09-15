class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int last = arr[0], ans = 1, cnt = 1;
        int order = 0;
        // 0 - anything, 1 - increasing, -1 - decreasing
        for (int i = 1; i < arr.size(); i++) {
            if (last == arr[i]) {
                ans = max(ans, cnt);
                cnt = 1;
                order = 0;
            } else if (order == 0) {
                order = (last < arr[i] ? -1 : 1);
                cnt++;
            } else if ((order == 1 && last < arr[i]) || (order == -1 && last > arr[i])) {
                cnt++;
                order *= -1;
            } else {
                ans = max(ans, cnt);
                cnt = 2;
            }
            last = arr[i];
        }
        ans = max(ans, cnt);
        return ans;
    }
};