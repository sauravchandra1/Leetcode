class Solution {
    public:
        string removeDuplicateLetters(string s) {
            const int SIZE = 26;
            vector < bool > visited(SIZE, false);
            vector < int > multiplicity(SIZE, 0);
            string answer;
            for (const char c: s) {
                multiplicity[c - 'a']++;
            }
            for (const char c: s) {
                multiplicity[c - 'a']--;
                if (visited[c - 'a']) {
                    continue;
                }
                while (!answer.empty() && c < answer.back() && multiplicity[answer.back() - 'a'] > 0) {
                    visited[answer.back() - 'a'] = false;
                    answer.pop_back();
                }
                answer.push_back(c);
                visited[c - 'a'] = true;
            }
            return answer;
        }
};