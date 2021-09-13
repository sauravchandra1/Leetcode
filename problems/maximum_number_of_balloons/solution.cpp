class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0, a = 0, l = 0, o = 0, n = 0;
        for (auto& c : text) {
            switch(c) {
                case 'b':
                    b++;
                    break;
                case 'a':
                    a++;
                    break;
                case 'l':
                    l++;
                    break;
                case 'o':
                    o++;
                case 'n':
                    n++;
            }
        }
        o /= 2;
        l /= 2;
        b = min(b, a);
        l = min(l, o);
        b = min(b, l);
        return min(b, n);
    }
};