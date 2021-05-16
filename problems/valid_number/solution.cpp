class Solution {
public:
    bool isNumber(string s) {
        bool is_decimal = false;
        int idx;
        int len = s.size();
        auto isInteger = [&](int l, int r) {
            for (int i = l; i <= r; i++) 
                if (s[i] < '0' || s[i] > '9') 
                    return false;
            return true;
        };
        auto isExp = [&](int l, int r) {
            bool is_exp = false;
            int idx;
            for (int i = l; i <= r; i++) {
                if (s[i] == 'e' || s[i] == 'E') {
                    is_exp = true;
                    idx = i;
                    break;
                }
            }
            if (!is_exp) return isInteger(l, r);
            int l1 = idx - l, l2 = r - idx;
            if (!l2) return false;
            if (!isInteger(l, idx - 1)) return false;
            if ((s[idx + 1] == '+' || s[idx + 1] == '-') && l2 > 1) return isInteger(idx + 2, r);
            if ((s[idx + 1] == '+' || s[idx + 1] == '-') && l2 == 1) return false;
            else return isInteger(idx + 1, r);
        };
        for (int i = 0; i < len; i++) {
            if (s[i] == '.') {
                is_decimal = true;
                idx = i;
                break;
            }
        }
        bool digit = false;
        for (int i = 0; i < len; i++) {
            if (s[i] == 'e' || s[i] == 'E' && !digit) return false;
            if (s[i] >= '0' && s[i] <= '9') break;
        }
        if (!is_decimal) {
            
            if (s[0] == 'e' || s[0] == 'E') return false;
            if ((s[0] == '+' || s[0] == '-') && len > 1 && isExp(1, len - 1)) return true;
            if (isExp(0, len - 1)) return true;
            if ((s[0] == '+' || s[0] == '-') && len > 1) return isInteger(1, len - 1);
            else return isInteger(0, len - 1);
        } else {
            int l1 = idx, l2 = len - idx - 1;
            if (!l1 && !l2) return false;
            if (l2 == 0 && l1 == 1 && (s[0] == '+' || s[0] == '-')) return false;
            if (s[0] == '+' || s[0] == '-') {
                if (!isInteger(1, idx - 1)) return false;
            } else if (!isInteger(0, idx - 1)) return false;
            if ((s[idx + 1] == 'e' || s[idx + 1] == 'E') && !l1) return false;
            return isExp(idx + 1, len - 1);
        }
    }
};