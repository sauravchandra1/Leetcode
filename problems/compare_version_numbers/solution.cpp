class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> vec1, vec2;
        int num = 0;
        for (int i = 0; i < version1.size(); i++) {
            if (version1[i] == '.') {
                vec1.push_back(num);
                num = 0;
                continue;
            } else {
                num = num * 10 + (int)(version1[i] - '0');
            }
        }
        if (num != 0) vec1.push_back(num);
        num = 0;
        for (int i = 0; i < version2.size(); i++) {
            if (version2[i] == '.') {
                vec2.push_back(num);
                num = 0;
                continue;
            } else {
                num = num * 10 + (int)(version2[i] - '0');
            }
        }
        if (num != 0) vec2.push_back(num);
        int l1 = vec1.size(), l2 = vec2.size();
        int val1, val2;
        for (int i = 0; i < max(l1, l2); i++) {
            val1 = val2 = 0;
            if (i < l1) val1 = vec1[i];
            if (i < l2) val2 = vec2[i];
            if (val1 < val2) return -1;
            if (val1 > val2) return 1;
        }
        return 0;
    }
};