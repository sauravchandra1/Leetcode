class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char c = keysPressed[0];
        int ans = releaseTimes[0];
        for (int i = 1; i < releaseTimes.size(); i++) {
            if ((releaseTimes[i] - releaseTimes[i - 1] > ans) || 
                (releaseTimes[i] - releaseTimes[i - 1] == ans && keysPressed[i] > c)) {
                ans = releaseTimes[i] - releaseTimes[i - 1];
                c = keysPressed[i];
            } 
        }
        return c;
    }
};