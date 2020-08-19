class FreqStack {
    public:
        map < int, int > mp;
    map < int, stack<int> > count;
    int mxfreq = 0;
    FreqStack() {
        mxfreq = 0;
    }

    void push(int x) {
        mp[x]++;
        count[mp[x]].push(x);
        if (mxfreq < mp[x])
            mxfreq = mp[x];
    }

    int pop() {
        int temp;
        if (!count[mxfreq].empty()) {
            temp = count[mxfreq].top();
            count[mxfreq].pop();
            mp[temp]--;
        }
        if (count[mxfreq].empty())
            mxfreq = mxfreq - 1;
        return temp;
    }
};