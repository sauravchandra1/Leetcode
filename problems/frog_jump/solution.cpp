class Solution {
    public:
        bool canCross(vector < int > & stones) {
            if (stones[1] != 1) return 0;

            for (int i = 3; i < stones.size(); i++)
                if (stones[i] > stones[i - 1] * 2) return false;

            unordered_set < int > s(stones.begin(), stones.end());
            stack < int > positions, jump;

            int endStone = stones.back();
            positions.push(0);
            jump.push(0);

            while (!positions.empty()) {
                int p = positions.top();
                positions.pop();
                int j = jump.top();
                jump.pop();

                if (p == endStone) return true;

                for (int i = j - 1; i <= j + 1; i++) {
                    if (i <= 0) continue;
                    if (s.count(p + i)) {
                        positions.push(p + i);
                        jump.push(i);
                    }
                }
            }
            return false;
        }
};