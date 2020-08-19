class Solution {
    public:
        int subarraysDivByK(vector < int > & A, int K) {
            unordered_map < int, int > mpp;
            mpp[0] = 1;
            int cumsum = 0, ans = 0;
            for (int i = 0; i < A.size(); i++) {
                cumsum += A[i];
                int rem = cumsum % K;
                if (rem < 0) rem += K;
                ans += mpp[rem];
                mpp[rem]++;

            }
            return ans;
        }
};