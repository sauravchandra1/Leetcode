class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        auto len = gas.size();
        auto left = 0;
        auto sum = 0;
        auto ret = 0;
        for (auto i = 0; i < len; ++i) {
            sum += gas[i] - cost[i];
            if (sum < 0) {
                left += sum;
                ret = i + 1;
                sum = 0;
                continue;
            }
        } 
        return (sum + left >= 0) ? ret : -1;
    }
};