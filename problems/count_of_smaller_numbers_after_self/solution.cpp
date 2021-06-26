class Fenwick {
    vector<int> F;
    int n;
public:
    Fenwick(int n) : F(n + 1) { this->n = n; }
    void add(int i, int val) {
        i++;
        while (i <= n) {
            F[i] += val;
            i += (i & -i);
        }
    }
    int getSum(int i) {
        i++;
        int sum = 0;
        while (i > 0) {
            sum += F[i];
            i -= (i & -i);
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(nums.begin(), nums.end());
        sort(vec.begin(), vec.end());
        unordered_map<int, int> rank;
        Fenwick F(n);
        for (int i = 0; i < n; i++) rank[vec[i]] = i + 1;
        for (int i = n - 1; i >= 0; i--) {
            int val = rank[nums[i]];
            nums[i] = F.getSum(val - 1);
            F.add(val, 1);
        }
        return nums;
    }
};