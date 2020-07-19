class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> let;
        vector<int> dig;
        for (int i = 0; i < logs.size(); i++) {
            int pos = logs[i].find(' ') + 1;
            string new_str = logs[i].substr(pos);
            if (new_str[0] >= '0' && new_str[0] <= '9') dig.push_back(i);
            else let.push_back(make_pair(new_str, logs[i].substr(0, pos)));
        }
        sort(let.begin(), let.end(), [] (const pair<string, string> &a, 
                                         const pair<string, string> &b){
            if (a.first == b.first) return (a.second < b.second);
            else return (a.first < b.first);
        });
        vector<string> ans;
        for (auto p : let) ans.push_back(p.second + p.first);
        for (auto p : dig) ans.push_back(logs[p]);
        return ans;
    }
};