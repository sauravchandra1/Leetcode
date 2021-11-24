class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n1 = firstList.size(), n2 = secondList.size();
        int l1 = 0, l2 = 0;
        vector<vector<int>> ans;
        while (l1 < n1 && l2 < n2) {
            int l = max(firstList[l1][0], secondList[l2][0]);
            int r = min(firstList[l1][1], secondList[l2][1]);
            if (l <= r) ans.push_back({l, r});
            if (firstList[l1][1] < secondList[l2][1]) l1++;
            else if (secondList[l2][1] < firstList[l1][1]) l2++;
            else {
                l1++, l2++;
            }
        }
        return ans;
    }
};