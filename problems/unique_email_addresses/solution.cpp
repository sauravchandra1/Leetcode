class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        bool seen_a, seen_plus;
        unordered_set<string> se;
        for (auto& v : emails) {
            seen_a = seen_plus = false;
            string str;
            for (int i = 0; i < v.size(); i++) {
                if (seen_a) {
                    str += v[i];
                    continue;
                } 
                if (v[i] == '@') {
                    seen_a = true;
                    str += v[i];
                    continue;
                }
                if (seen_plus) continue;
                if (v[i] == '+') {
                    seen_plus = true;
                    continue;
                }
                if (v[i] != '.') str += v[i];
            }
            se.insert(str);
        }
        return se.size();
    }
};