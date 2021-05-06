class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    vector<int> vec;
    const int N = 30004;
    int idx;
    MinStack() {
        idx = 0;
        vec.resize(N, 0);
    }
    
    void push(int x) {
        stk.push(x);
        if (idx == 0) vec[idx++] = x;
        else vec[idx++] = min(vec[idx - 1], x);
    }
    
    void pop() {
        idx--;
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return vec[idx - 1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */