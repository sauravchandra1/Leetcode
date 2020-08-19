class Solution {
    public:
        int dis(const string & s1,
            const string & s2) {
            int res = 0;
            for (int i = 0; i < 6; ++i)
                res += s1[i] != s2[i];
            return res;
        }

    void findSecretWord(vector < string > & wordlist, Master & master) {
        int n = wordlist.size();
        vector < vector < vector < int >>> neib(n, vector < vector < int >> (7));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int d = dis(wordlist[i], wordlist[j]);
                neib[i][d].push_back(j);
                neib[j][d].push_back(i);
            }
        }
        unordered_set < int > candi;
        for (int i = 0; i < n; ++i)
            candi.insert(i);
        for (int t = 0; t < 10; ++t) {
            priority_queue < pair < double, int >> que;
            for (int can: candi) {
                double entro = 0.0;
                for (int d = 1; d <= 6; ++d) {
                    int cnt = 0;
                    for (int nei: neib[can][d]) {
                        cnt += candi.count(nei);
                    }
                    if (cnt != 0) {
                        double p = cnt / (candi.size() - 1.0);
                        entro += -log(p) * p;
                    }
                }
                que.push({
                    entro,
                    can
                });
            }
            int chosen = que.top().second;
            int res = master.guess(wordlist[chosen]);
            if (res == 6)
                return;
            unordered_set < int > nxt;
            for (int nei: neib[chosen][6 - res]) {
                if (candi.count(nei))
                    nxt.insert(nei);
            }
            swap(candi, nxt);
        }
    }
};