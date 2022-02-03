class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0, sum, l, r, c1, c2;
        sort(nums3.begin(), nums3.end());
        sort(nums4.begin(), nums4.end());
        unordered_map<int, int> mp;
        int res = 0;
        for (auto& v1 : nums1) {
            for (auto& v2 : nums2) {
                sum = -(v1 + v2);
                l = 0, r = nums4.size() - 1;
                if (mp.count(sum) > 0) {
                    ans += mp[sum];
                    continue;
                }
                res = 0;
                while (l < nums3.size() && r >= 0) {
                    if (nums3[l] + nums4[r] == sum) {
                        c1 = c2 = 1;
                        while (l + 1 < nums3.size() && nums3[l] == nums3[l + 1]) {
                            l++;
                            c1++;
                        }
                        while (r - 1 >= 0 && nums4[r] == nums4[r - 1]) {
                            r--;
                            c2++;
                        }
                        l++, r--;
                        res += c1 * c2;
                    } else if (nums3[l] + nums4[r] > sum) {
                        r--;
                    } else {
                        l++;
                    }
                }
                mp[sum] = res;
                ans += res;
            }
        }
        return ans;
    }
};