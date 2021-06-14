class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1]) return (a[0] > b[0]);
            return (a[1] > b[1]);
        });
        int len = boxTypes.size();
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (boxTypes[i][0] <= truckSize) {
                ans += (boxTypes[i][0] * boxTypes[i][1]);
                truckSize -= boxTypes[i][0];
            } else {
                ans += (truckSize * boxTypes[i][1]);
                break;
            }
        }
        return ans;
    }
};