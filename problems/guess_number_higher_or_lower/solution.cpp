/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n, m, res;
        while (l < r) {
            m = l + (r - l) / 2;
            res = guess(m);
            if (res == 0) return m;
            else if (res > 0) 
                l = m + 1;
            else 
                r = m - 1;
        }
        return l;
    }
};