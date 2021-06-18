const int N = 30004;

class Fenwick {
    vector<int> F;
    int n;
public:
    Fenwick(int n) : F(n + 1) { this->n = n; }
    void add(int i, int val) {
        i++;
        while (i <= n) {
            F[i] += val;
            i += i & -i;
        }
    }
    int getSum(int i) {
        i++;
        int sum = 0;
        while (i > 0) {
            sum += F[i];
            i -= i & -i;
        }
        return sum;
    }
};

class NumArray {
    Fenwick F;
    vector<int> num;
public:
    NumArray(vector<int>& nums) : F(N) {
        for (int i = 0; i < nums.size(); i++) { 
            F.add(i, nums[i]);
            num.push_back(nums[i]);
        }
    }
    
    void update(int index, int val) {
        int v = -num[index] + val;
        num[index] = val;
        F.add(index, v);
    }
    
    int sumRange(int left, int right) {
        return F.getSum(right) - F.getSum(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */