class MyCalendar {
public:
    vector<pair<int,int>> vec;
    int len;
    const int N = 1000;
    MyCalendar() {
        vec.resize(N);
        len = 0;
    }
    
    bool book(int start, int end) {
        for (int i = 0; i < len; i++) {
            if (start >= vec[i].first && start < vec[i].second) return false;
            if (end > vec[i].first && end <= vec[i].second) return false;
            if (start > vec[i].first && end < vec[i].second) return false;
            if (vec[i].first > start && vec[i].second < end) return false;
        }
        vec[len++] = {start, end};
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */