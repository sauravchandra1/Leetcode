class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
       /*
            (a + ib) * (c + id) = (ac - bd) + i(bc + ad);
       */
        int l1 = num1.size(), l2 = num2.size();
        int a = 1, b = 1, c = 1, d = 1;
        
        auto isInt = [](char c) {
            return (c < '0' || c > '9') ? false : true;
        };
        
        bool ok = true;
        int i = 0;
        
        auto get = [&]() {
            int t = 0;
            if (ok) {
                while (i < l1 && isInt(num1[i])) {
                    t = t * 10 + (num1[i] - '0');
                    i++;
                }
            } else {
                while (i < l2 && isInt(num2[i])) {
                    t = t * 10 + (num2[i] - '0');
                    i++;
                }
            }
            return t;
        };
        
        if (num1[i] == '-') {
            a = -1;
            i++;
        }
        a = a * get();
        i++;
        if (num1[i] == '-') {
            b = -1;
            i++;
        }
        b = b * get();
        
        i = 0;
        ok = false;
        
        if (num2[i] == '-') {
            c = -1;
            i++;
        }
        c = c * get();
        i++;
        if (num2[i] == '-') {
            d = -1;
            i++;
        }
        d = d * get();
        
        int e = a * c - b * d;
        int f = b * c + a * d;
        
        return to_string(e) + "+" + to_string(f) + "i";
    }
};