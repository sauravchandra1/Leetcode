class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for (auto& v : position) (v & 1 ? odd++ : even++);
        return min(odd, even);
    }
};