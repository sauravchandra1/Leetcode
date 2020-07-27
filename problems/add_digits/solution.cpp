class Solution {
public:
    int addDigits(int num) {
        function<int(int)> dfs = [&](int num) {
            if (num >= 0 && num <= 9) return num;
            int sum = 0;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            return dfs(sum);  
        };
        return dfs(num);
    }
};