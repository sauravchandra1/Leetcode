class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> Max;
    priority_queue<int, vector<int>, greater<int>> Min;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (Max.size() == 0 && Min.size() == 0) {
            Max.push(num);
        } else if (num < Max.top()) {
            Max.push(num);
        } else {
            Min.push(num);
        }
        if (abs((int)Max.size() - (int)Min.size()) == 2) {
            if (Max.size() > Min.size()) {
                num = Max.top();
                Max.pop();
                Min.push(num);
            } else {
                num = Min.top();
                Min.pop();
                Max.push(num);
            }
        }
    }
    
    double findMedian() {
        double a, b, ans = 0;
        int szMax = Max.size();
        int szMin = Min.size();
        if (!szMax && !szMin) return ans;
        if (szMax == szMin) {
            a = Max.top();
            b = Min.top();
            ans = (a + b) / 2.0;
            return ans;
        } else if (szMax > szMin){
            return Max.top();
        } else {
            return Min.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */