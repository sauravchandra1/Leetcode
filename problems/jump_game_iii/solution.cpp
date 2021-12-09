class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> Q;
        Q.push(start);
        while (!Q.empty()) {
            int i = Q.front();
            Q.pop();
            if (arr[i] == 0) return true;
            if (i - arr[i] >= 0 && arr[i - arr[i]] != -1) Q.push(i - arr[i]);
            if (i + arr[i] < arr.size() && arr[i + arr[i]] != -1) Q.push(i + arr[i]);
            arr[i] = -1;
        }
        return false;
    }
};