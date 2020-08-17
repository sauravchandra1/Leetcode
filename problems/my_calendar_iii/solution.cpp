class MyCalendarThree {
public:
    map < int, int > mp;
    MyCalendarThree() {}
    int book(int s, int e) {
        mp[s]++;
        mp[e]--;
        int ans = 0;
        auto it = mp.begin();
        int open = 0;
        while (it != mp.end()) {
            open += it -> second;
            ans = max(ans, open);
            it++;
        }
        return ans;
    }
};