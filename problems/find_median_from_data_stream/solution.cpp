class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int> ans;
    multiset<int> :: iterator it;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (ans.size() == 0) {
            it = ans.insert(num);
            return ;
        }
        ans.insert(num);
        if (ans.size() % 2 == 0 && num >= *it) it++;
        if (ans.size() & 1 && num < *it) it--;
    }
    
    double findMedian() {
        if (ans.size() & 1LL) return *it;
        else return (double)(*it + *prev(it)) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */