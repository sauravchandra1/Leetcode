class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int diff = INT_MAX;
        for (int i = 1; i < arr.size(); i++) {
            if (diff > arr[i] - arr[i - 1]) {
                ans.clear();
                diff = arr[i] - arr[i - 1];
                ans.push_back({arr[i - 1], arr[i]});
            } else if (diff == arr[i] - arr[i - 1])
                ans.push_back({arr[i - 1], arr[i]});
        }
        return ans;
    }
};