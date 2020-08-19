class Solution {
    public:
        bool partition(vector < int > & nums, int k, int sum, int times, int total, bool vis[], int index) {
            if (times + 1 == k) {
                return true;
            }
            if (sum == total) {
                return partition(nums, k, sum, times + 1, 0, vis, 0);
            }
            for (int i = index; i < nums.size(); i++) {
                if (!vis[i] && total + nums[i] <= sum) {
                    vis[i] = true;
                    if (partition(nums, k, sum, times, total + nums[i], vis, i + 1))
                        return true;
                    vis[i] = false;
                }
            }
            return false;
        }

    bool canPartitionKSubsets(vector < int > & nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k || k > n)
            return false;
        bool vis[n];
        memset(vis, false, sizeof(vis));
        return partition(nums, k, sum / k, 0, 0, vis, 0);
    }
};