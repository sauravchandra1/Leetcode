class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int len = num.size();
        int i;
        for(i = len - 1; i >= 1; --i) {
            if(num[i - 1] < num[i]) break;
        }
        if(i == 0) return -1;  
        i--;
        char mingr = ':';
        int minind = i + 1;
        for(int j = i + 1; j < len; ++j) {
            if(num[j] < mingr && num[j] > num[i]) {
                mingr = num[j];
                minind = j;
            }
        }
        swap(num[i], num[minind]);
        sort(num.begin() + i + 1, num.begin() + num.length());
        if(num.length() >= to_string(INT_MAX).length() && num > to_string(INT_MAX))
            return -1;
        return stoi(num);
    }
};