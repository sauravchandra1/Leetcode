class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = nums.size();
        int l = 0, ans = 0, _max = 0, cnt = k;
        for (int i = 0; i < len; i++) {
            if (nums[i]) _max++;
            else {
                if (k) {
                    k--;
                    _max++;
                } else { 
                    if (!cnt) {
                        _max = 0;
                        continue;
                    }
                    while (l < i && nums[l]) l++;
                    _max = i - l;
                    l++;
                }
            }
            ans = max(ans, _max);
        }
        return ans;
    }
};