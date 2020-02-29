class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = 100000;
        map<int, int> ind;
        map<int, bool> vis;
        for (int i = 0; i < N; i++) {
            vis[i] = false;
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            ind[num] = i;
            vis[num] = true;
        }
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int rem = target - num;
            if (vis[rem] && (ind[rem] != i)) {
                ans.push_back(min(i, ind[rem]));
                ans.push_back(max(i, ind[rem]));
                break;
            }
        }
        return ans;
    }
};