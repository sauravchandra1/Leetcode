class Solution {
public:
    string frequencySort(string s) {
        const int N = 62;
        vector<int> vec(N);
        auto get = [&](char v) {
            if (v >= 'a' && v <= 'z') return (v - 'a' + 10);
            else if (v >= 'A' && v <= 'Z') return (v - 'A' + 36);
            else return (v - '0');
        };
        for (auto& v : s) vec[get(v)]++;
        sort(s.begin(), s.end(), [&](const char& a, const char& b) {
            int c1 = get(a), c2 = get(b);
            if (vec[c1] == vec[c2]) return c1 > c2;
           return (vec[c1] > vec[c2]); 
        });
        return s;
    }
};