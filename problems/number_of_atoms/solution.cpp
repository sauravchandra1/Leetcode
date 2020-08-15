class Solution {
    public:
        string countOfAtoms(string f) {
            map < string, int > mp;
            int num = 0, n = f.size();
            stack < map < string, int > > st;
            string str = "";
            for (int i = 0; i < f.size(); i++) {
                if (f[i] == '(') { 
                    st.push(mp);
                    mp.clear();
                } else if (f[i] == ')') { 
                    num = 0;
                    while (i + 1 < n && f[i + 1] >= '0' && f[i + 1] <= '9') {
                        num = (num * 10) + (f[i + 1] - '0');
                        i++;
                    }
                    num = max(num, 1);
                    for (auto & it: mp)
                        it.second *= num;
                    for (auto it: st.top())
                        mp[it.first] += it.second;
                    st.pop();
                } else if (f[i] >= 'A' && f[i] <= 'Z') {
                    str = "";
                    str += f[i];
                    while (i + 1 < n && f[i + 1] <= 'z' && f[i + 1] >= 'a') {
                        str += f[i + 1];
                        i++;
                    }
                    num = 0;
                    while (i + 1 < n && f[i + 1] >= '0' && f[i + 1] <= '9') {
                        num = (num * 10) + (f[i + 1] - '0');
                        i++;
                    }
                    mp[str]++;
                    if (num > 0)
                        mp[str] += num - 1;
                }
            }
            while (!st.empty()) {
                for (auto it: st.top())
                    mp[it.first] += it.second;
                st.pop();
            }
            string ans = "";
            for (auto it: mp) {
                ans += it.first;
                if (it.second > 1)
                    ans += to_string(it.second);
            }
            return ans;
        }
};