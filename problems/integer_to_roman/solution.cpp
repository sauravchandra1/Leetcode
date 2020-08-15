class Solution {
    public:
        string sym = "IVXLCDM";
    int val[7] = {
        1,
        5,
        10,
        50,
        100,
        500,
        1000
    };
    vector < pair < int, string > > v;
    string ans;
    map < int, int > used;
    string intToRoman(int num) {
        for (int i = 0; i < sym.size(); i++) {
            string cur = "";
            cur += sym[i];
            v.push_back({
                val[i],
                cur
            });
        }
        v.push_back({
            9,
            "IX"
        });
        v.push_back({
            4,
            "IV"
        });
        v.push_back({
            90,
            "XC"
        });
        v.push_back({
            40,
            "XL"
        });
        v.push_back({
            900,
            "CM"
        });
        v.push_back({
            400,
            "CD"
        });
        sort(v.begin(), v.end());
        int pos = v.size() - 1;
        while (num > 0) {
            while (num >= v[pos].first) {
                num -= v[pos].first;
                ans += v[pos].second;
            }
            pos--;
        }
        return ans;
    }
};