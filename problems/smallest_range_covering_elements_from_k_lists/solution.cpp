class Solution {
    public:
        vector < int > smallestRange(vector < vector < int >> & nums) {
            int high = INT_MIN;
            int low;
            int n = nums.size();
            priority_queue < pair < int, pair < int, int >> , vector < pair < int, pair < int, int >>> , greater < pair < int, pair < int, int >>> > pq;
            for (int i = 0; i < n; i++) {
                high = max(high, nums[i][0]);
                pq.push({
                    nums[i][0],
                    {
                        i,
                        0
                    }
                });
            }
            low = pq.top().first;
            vector < int > res {
                low,
                high
            };
            while (pq.size() == n) {
                auto it = pq.top();
                pq.pop();
                int val = it.first;
                int row = it.second.first;
                int col = it.second.second;

                if (col + 1 < nums[row].size()) {
                    pq.push({
                        nums[row][col + 1],
                        {
                            row,
                            col + 1
                        }
                    });
                    high = max(high, nums[row][col + 1]);
                    low = pq.top().first;
                    if (high - low < res[1] - res[0]) {
                        res[1] = high;
                        res[0] = low;
                    }
                }
            }
            return res;
        }
};