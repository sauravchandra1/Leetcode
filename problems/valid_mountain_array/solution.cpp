class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 1, len = arr.size();
        if (len < 3) return false;
        while (i < len && arr[i - 1] < arr[i]) i++;
        if (i == len || i == 1) return false;
        while (i < len && arr[i - 1] > arr[i]) i++;
        if (i == len) return true;
        return false;
    }
};