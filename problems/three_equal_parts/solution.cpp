class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int len = arr.size();
        int cnt = accumulate(arr.begin(), arr.end(), 0);
        if (cnt % 3) return {-1, -1};
        if (!cnt) return {0, 2};
        int l = cnt / 3;
        int i, j, c = 0;
        for (i = 0; i < len; i++) {
            c += arr[i];
            if (c == l) break;
        }
        c = 0;
        for (j = i + 1; j < len; j++) {
            c += arr[j];
            if (c == l) break;
        }
        int p = 0, q = i + 1, r = j + 1;
        int l1 = 0, l2 = 0;
        while (!arr[p]) p++;
        while (!arr[q]) q++, l1++;
        while (!arr[r]) r++, l2++;
        for (; p <= i && q <= j && r < len; p++, q++, r++) {
            c = arr[p] + arr[q] + arr[r];
            if (c == 0 || c == 3) continue;
            return {-1, -1};
        }
        if (r < len) {
            int d = len - r;
            if (min(l1, l2) >= d) return {i + d, j + 1 + d};
            else return {-1, -1};
        }
        return {i, j + 1};
    }
};