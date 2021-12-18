class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int len = digits.size();
        vector<int> nums;
        for (auto v : digits) nums.push_back(v[0] - '0');
        auto cntDigit = [&](int x) {
            int res = 0;
            while (x) { x /= 10; res++; }
            return res;
        };
        auto cntLow = [&](int d) {
            int ans = 0;
            for (int i = 0; i < len; i++) {
                if (nums[i] < d) ans++; 
                else break;
            }
            return ans;
        };
        vector<int> t(10);
        for (auto& v : nums) t[v] = 1;
        auto presentAll = [&](string num) {
            for (auto& v : num) if (!t[v - '0']) return false;
            return true;
        };
        int d = cntDigit(n), ans = 0;
        long long l = len;
        for (int i = 1; i < d; i++) {
            ans += l;
            l *= len;
        }
        l /= len;
        string num = to_string(n);
        for (int i = 0; i < num.size(); i++) {
            ans += cntLow(num[i] - '0') * l;
            l /= len;
            if (!t[num[i] - '0']) break;
        }
        if (presentAll(num)) ans++;
        return ans;
    }
};