class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for (auto& v : word) if (v <= 'Z') cnt++;
        if (cnt == word.size() || cnt == 0 || cnt == 1 && word[0] <= 'Z') return true;
        return false;
    }
};