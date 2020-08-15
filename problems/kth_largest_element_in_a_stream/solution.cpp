class KthLargest {
public:
    struct cmp {
        bool operator()(const int &a, const int &b) {
            return a > b;
        }
    };
    int K;
    priority_queue<int, vector<int>, cmp> pq;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (auto v : nums) {
            pq.push(v);
            if (pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > K) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */