class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector<int> index(len);
        iota(index.begin(), index.end(), 0);
        vector<int> ans(len, 0);
        sort(index.begin(), index.end(), [&](const int& i, const int& j) {
            return (ratings[i] < ratings[j]);
        });
        int val, sum = 0;
        for (auto& i : index) {
            val = 0;
            if (i - 1 >= 0 && ratings[i - 1] < ratings[i]) 
                if (ans[i - 1] > val) val = ans[i - 1];
            if (i + 1 < len && ratings[i + 1] < ratings[i]) 
                if (ans[i + 1] > val) val = ans[i + 1];
            ans[i] = val + 1;
            sum += ans[i];
        }
        return sum;
    }
};