class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<vector<int>> dp(len1, vector<int> (len2, -1));
        function<int(int, int)> dfs = [&](int l1, int l2) {
            if (l1 == len1 || l2 == len2) return 0;
            auto& res = dp[l1][l2];
            if (res != -1) return res;
            res = 0;
            if (nums1[l1] == nums2[l2]) 
                res = dfs(l1 + 1, l2 + 1) + 1;
            return res;
        };
        int ans = 0;
        for (int i = 0; i < len1; i++) 
            for (int j = 0; j < len2; j++) 
                ans = max(ans, dfs(i, j));
        return ans;
    }
};