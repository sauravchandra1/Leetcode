class Solution {
    public:
        vector < int > temp;
    Solution(vector < int > & nums) {
        temp = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector < int > reset() {
        vector < int > res;
        res = temp;
        return res;
    }

    /** Returns a random shuffling of the array. */
    vector < int > shuffle() {
        vector < int > res;
        res = temp;
        int n = temp.size();
        for (int i = n - 1; i >= 1; --i) {
            int j = rand() % (i + 1);
            swap(res[i], res[j]);
        }
        return res;
    }
};