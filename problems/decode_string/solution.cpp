class Solution {
    public:
        string decodeString(string s) {
            int size = s.size();
            int i = 0;
            string result;
            stack < string > strStack;
            stack < int > intStack;
            while (i < size) {
                if (isdigit(s[i])) {
                    string numS;
                    while (isdigit(s[i]))
                        numS += s[i++];
                    stringstream ss(numS);
                    int num;
                    ss >> num;
                    intStack.push(num);
                } else if (s[i] == '[') {
                    strStack.push(result);
                    result.clear();
                    ++i;
                } else if (isalpha(s[i]))
                    result += s[i++];
                else if (s[i] == ']') {
                    string str(strStack.top());
                    strStack.pop();
                    int count = intStack.top();
                    intStack.pop();
                    for (int i = 0; i < count; ++i)
                        str += result;
                    result = str;
                    ++i;
                }
            }
            return result;
        }
};