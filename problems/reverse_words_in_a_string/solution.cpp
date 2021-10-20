class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        stringstream ss(s);
        string str;
        while (ss >> str) vec.push_back(str);
        s = "";
        for (int i = vec.size() - 1; i >= 0; i--) s += vec[i] + " ";
        s.pop_back();
        return s;
    }
};