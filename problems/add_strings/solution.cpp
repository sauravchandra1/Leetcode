class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
        int sum, carry = 0;
        auto add = [&](int a, int b) {  
            sum = a + b + carry;
            carry = sum / 10;
            sum -= 10 * carry;
        };
        string ans;
        while (n1 >= 0 && n2 >= 0) {
            add(num1[n1] - '0', num2[n2] - '0');
            ans += sum + '0';
            n1--, n2--;
        }
        while (n1 >= 0) {
            add(num1[n1] - '0', 0);
            ans += sum + '0';
            n1--;
        }
        while (n2 >= 0) {
            add(num2[n2] - '0', 0);
            ans += sum + '0';
            n2--;
        }
        if (carry) ans += carry + '0';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};