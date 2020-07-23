class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<vector<int>> vec;
        auto get = [&]() {
            for (int i = 0; i < cells.size(); i++) {
                if (i == 0 || i == cells.size() - 1) cells[i] = 0;
                else if (vec.back()[i - 1] == vec.back()[i + 1]) cells[i] = 1;
                else cells[i] = 0;
            }   
        };   
        map<vector<int>, bool> mp;
        vec.push_back(cells);
        mp[cells] = true;
        for (int i = 0; i < N; i++) {
            get();
            if (mp.count(cells) > 0) {
                break;
            }
            vec.push_back(cells);
            mp[cells] = true;
        }
        int cnt = 0 ;
        if (N < vec.size()) return vec[N];
        cnt = find(vec.begin(), vec.end(), cells) - vec.begin();
        int cc = vec.size() - cnt;
        return vec[(N % cc - cnt % cc + cc) % cc + cnt];
    }
};