class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [&](const int& a, const int& b) {
            if (abs(a - x) == abs(b - x)) 
                return (a < b);
            else 
                return (abs(a - x) < abs(b - x));
        });
        arr.resize(k);
        sort(arr.begin(), arr.end());
        return arr;
    }
};