class Solution {
public:
    bool isValidSerialization(string preorder) {
        int len = preorder.size();
        if (len == 1 && preorder[0] == '#') return true;
        vector<int> stk;
        bool root = false;
        
        auto mark = [&]() {
            if (stk.size() == 0) return false;
            stk[stk.size() - 1]++;
            if (stk[stk.size() - 1] == 2) stk.pop_back();
            return true;
        };
        
        for (int i = 0; i < len; i++) {
            if (preorder[i] == '#') {
                if (!mark()) return false;
                i++;
            } else {
                while (i < len && preorder[i] != ',') i++;
                if (root && !mark()) return false;
                root = true;
                stk.push_back(0);
            }
        }
        return (stk.size() ? false : true);
    }
};