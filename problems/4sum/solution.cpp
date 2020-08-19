class Solution {
    public:
        vector < vector < int >> fourSum(vector < int > & nums, int target) {
            vector < vector < int >> output;
            sort(nums.begin(), nums.end());
            int n = nums.size();
            set < string > check;
            for (int i = 0; i < n - 3; i++) {
                for (int j = i + 1; j < n - 2; j++) {
                    int low = j + 1;
                    int high = n - 1;
                    while (high > low) {
                        int current = nums[i] + nums[j] + nums[low] + nums[high];
                        if (current == target) {
                            string s = to_string(nums[i]) + to_string(nums[j]) +
                                to_string(nums[low]) + to_string(nums[high]);
                            if (check.find(s) == check.end()) {
                                check.insert(s);
                                output.push_back({
                                    nums[i],
                                    nums[j],
                                    nums[low],
                                    nums[high]
                                });
                            }
                            low++, high--;
                        } else if (current > target) {
                            high--;
                        } else {
                            low++;
                        }
                    }
                }
            }
            return output;
        }
};